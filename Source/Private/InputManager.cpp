#include "DLog.h"
#include "DxUtil.h"
#include "InputManager.h"
#include "InputModifier.h"
#include "InputTrigger.h"
#include <algorithm>
#include <array>
#include <BindingContext.h>
#include <format>
#include <InputAction.h>
#include <memory>
#include <ranges>
#include <span>
#include <string>
#include <Types.h>
#include <vector>

InputManager::InputManager()
{
	mKeyValues.fill(0.0f);
}

void InputManager::ProcessKeyEvent(KeyEvent event)
{
	if (event.key == EKey::Unknown)
	{
		DLog::Warn("Unknown key code received.");
		return;
	}

	mPendingKeyEvents.push_back(event);
}

void InputManager::ActivateContext(const std::shared_ptr<const BindingContext>& context, uint8 priority)
{
	if (!context)
	{
		DLog::Error("Attempting to activate a NULL context.");
		return;
	}

	mActiveContexts.emplace_back(context, priority);

	std::ranges::sort(
		mActiveContexts,
		[priority](const ContextPriority& context1, const ContextPriority& context2)
		{
			return context1.priority < context2.priority;
		}
	);
}

bool InputManager::IsInputActionActive(const std::shared_ptr<const InputAction>& action) const
{
	const auto it = mLiveActions.find(action.get());
	if (it == mLiveActions.end())
	{
		return false;
	}
	const std::vector<BindingState>& trackedBindings = it->second;

	for (const BindingState& bindingState : trackedBindings)
	{
		if (bindingState.state == EActionState::Started || bindingState.state == EActionState::Triggered)
		{
			return true;
		}
	}

	return false;
}

void InputManager::ClearInputs()
{
	mKeyValues.fill(0.0f);
	mPendingKeyEvents.clear();
	mLiveActions.clear();
}

InputActionValue InputManager::ApplyModifiers(InputActionValue value, EActionValueType valueType,
	std::span<const std::unique_ptr<const InputModifier>> modifiers)
{
	InputActionValue modifiedValue = value;
	for (const auto& modifier : modifiers)
	{
		if (modifier)
		{
			modifiedValue = modifier->ModifyValue(modifiedValue, valueType);
		}
	}

	return modifiedValue;
}

bool InputManager::EvaluateTriggers(std::span<const std::unique_ptr<InputTrigger>> triggers, const InputActionValue actionValue, float deltaSeconds)
{
	if (triggers.empty())
	{
		return actionValue.IsNonZero();
	}

	for (const auto& trigger : triggers)
	{
		if (!trigger)
		{
			continue;
		}

		if (!trigger->Evaluate(actionValue, deltaSeconds))
		{
			return false;
		}
	}

	return true;
}

void InputManager::ResetTriggers(std::span<std::unique_ptr<InputTrigger> const> triggers)
{
	for (const auto& trigger : triggers)
	{
		if (!trigger)
		{
			continue;
		}
		trigger->Reset();
	}
}

void InputManager::Update(float deltaSeconds)
{
	for (const KeyEvent& event : mPendingKeyEvents)
	{
		mKeyValues[static_cast<std::size_t>(event.key)] = event.value;
		uint8 handledPriority = 255;

		for (const auto& [context, priority] : mActiveContexts)
		{
			if (!context)
			{
				DLog::Warn("NULL Binding Context in InputManager::Update()");
				continue;
			}

			// The key event has already been handled by a higher priority context
			if (handledPriority < priority)
			{
				continue;
			}

			const auto bindings = context->GetBindingsForKey(event.key);

			handledPriority = bindings.empty() ? handledPriority : priority;

			for (const auto& binding : bindings)
			{
				const InputAction* const action = context->GetAction(binding.actionHandle);
				ensure(action);

				auto [it, inserted] = mLiveActions.try_emplace(action, std::vector<BindingState>{});

				const bool alreadyTracked = std::ranges::any_of(
					it->second,
					[&binding, &context](const BindingState& trackedBinding)
					{
						return (&(trackedBinding.binding.get()) == &binding);
					}
				);

				if (!alreadyTracked)
				{
					it->second.emplace_back(binding);
				}
				ensure(it->second.size() > 0);
			}
		}
	}

	for (auto it = mLiveActions.begin(); it != mLiveActions.end();)
	{
		const InputAction* action = it->first;
		std::vector<BindingState>& trackedBindings = it->second;

		if (!action)
		{
			DLog::Warn("NULL Input Action in InputManager::Update()");
			it = mLiveActions.erase(it);
			continue;
		}

		InputActionValue combinedValue{};
		EActionState combinedState = EActionState::Ongoing;

		for (auto bindIt = trackedBindings.begin(); bindIt != trackedBindings.end();)
		{
			BindingState& bindingState = *bindIt;
			const BindingContext::Binding& binding = bindingState.binding;
			EActionState& actionState = bindingState.state;

			float keyValue = mKeyValues[static_cast<std::size_t>(binding.key)];

			InputActionValue modifiedValue = ApplyModifiers(
				InputActionValue(keyValue),
				action->GetValueType(),
				binding.modifiers
			);

			const bool satisfiesTriggers = EvaluateTriggers(binding.triggers, modifiedValue, deltaSeconds);
			const bool inputActive = modifiedValue.IsNonZero();


			if (satisfiesTriggers && inputActive)
			{
				switch (actionState)
				{
				case EActionState::Ongoing:
				{
					actionState = EActionState::Started;
					if (combinedState != EActionState::Triggered)
					{
						combinedState = EActionState::Started;
					}
					combinedValue += modifiedValue;
					break;
				}
				case EActionState::Started:
				{
					actionState = EActionState::Triggered;
					combinedState = EActionState::Triggered;
					combinedValue += modifiedValue;
					break;
				}
				case EActionState::Triggered:
				{
					combinedState = EActionState::Triggered;
					combinedValue += modifiedValue;
					break;
				}
				default: [[unlikely]]
					DLog::Error("Unexpected state for Input action");
					break;
				}
				++bindIt;
			}
			else if (inputActive) // satisfiesTriggers = false
			{
				switch (actionState)
				{
				case EActionState::Started:
				case EActionState::Triggered:
				{
					actionState = EActionState::Ongoing;
					if (combinedState != EActionState::Started && combinedState != EActionState::Triggered)
					{
						combinedState = EActionState::Interrupted;
					}
					ResetTriggers(binding.triggers);
					++bindIt;
					break;
				}
				case EActionState::Ongoing:
				{
					++bindIt;
					break;
				}
				default: [[unlikely]]
					DLog::Error("Unexpected state for Input action");
					++bindIt;
					break;
				}
			}
			else if (satisfiesTriggers) // inputActive = false
			{
				switch (actionState)
				{
				case EActionState::Ongoing:
				{
					actionState = EActionState::Started;
					if (combinedState != EActionState::Triggered)
					{
						combinedState = EActionState::Started;
					}
					combinedValue += modifiedValue;
					break;
				}
				case EActionState::Started:
				{
					actionState = EActionState::Triggered;
					combinedState = EActionState::Triggered;
					combinedValue += modifiedValue;
					break;
				}
				case EActionState::Triggered:
				{
					combinedState = EActionState::Triggered;
					combinedValue += modifiedValue;
					break;
				}
				default: [[unlikely]]
					DLog::Error("Unexpected state for Input action");
					break;
				}
			}
			else // satisfiesTriggers = false & inputActive = false
			{
				switch (actionState)
				{
				case EActionState::Started:
				case EActionState::Triggered:
				{
					actionState = EActionState::Completed;
					if (combinedState != EActionState::Started && combinedState != EActionState::Triggered)
					{
						combinedState = EActionState::Completed;
					}
					ResetTriggers(binding.triggers);

					bindIt = trackedBindings.erase(bindIt);
					break;
				}
				case EActionState::Ongoing:
				{
					if (inputActive)
					{
						if (combinedState != EActionState::Started && combinedState != EActionState::Triggered)
						{
							combinedState = EActionState::Ongoing;
						}
						++bindIt;
					}
					else
					{
						if (combinedState != EActionState::Started && combinedState != EActionState::Triggered)
						{
							combinedState = EActionState::Canceled;
						}
						ResetTriggers(binding.triggers);
						bindIt = trackedBindings.erase(bindIt);
					}

					break;
				}
				default: [[unlikely]]
					DLog::Error("Unexpected state for Input action");
					++bindIt;
					break;
				}
			}
		}

		if (combinedState == EActionState::Started)
		{
			//DLog::Log("InputManager Update - Frame {}", updateCount++);
			action->Invoke(EActionState::Started, combinedValue, deltaSeconds);
			action->Invoke(EActionState::Triggered, combinedValue, deltaSeconds);
		}
		else
		{
			//DLog::Log("InputManager Update - Frame {}", updateCount++);
			action->Invoke(combinedState, combinedValue, deltaSeconds);
		}

		if (trackedBindings.empty())
		{
			it = mLiveActions.erase(it);
		}
		else
		{
			++it;
		}
	}

	mPendingKeyEvents.clear();
	mKeyValues[static_cast<std::size_t>(EKey::MouseX)] = 0.0f;
	mKeyValues[static_cast<std::size_t>(EKey::MouseY)] = 0.0f;
}

std::string GetStringForKey(EKey key)
{
	switch (key)
	{
		// Letters
	case EKey::A: return "A";
	case EKey::B: return "B";
	case EKey::C: return "C";
	case EKey::D: return "D";
	case EKey::E: return "E";
	case EKey::F: return "F";
	case EKey::G: return "G";
	case EKey::H: return "H";
	case EKey::I: return "I";
	case EKey::J: return "J";
	case EKey::K: return "K";
	case EKey::L: return "L";
	case EKey::M: return "M";
	case EKey::N: return "N";
	case EKey::O: return "O";
	case EKey::P: return "P";
	case EKey::Q: return "Q";
	case EKey::R: return "R";
	case EKey::S: return "S";
	case EKey::T: return "T";
	case EKey::U: return "U";
	case EKey::V: return "V";
	case EKey::W: return "W";
	case EKey::X: return "X";
	case EKey::Y: return "Y";
	case EKey::Z: return "Z";

		// Numbers
	case EKey::Num0: return "Num0";
	case EKey::Num1: return "Num1";
	case EKey::Num2: return "Num2";
	case EKey::Num3: return "Num3";
	case EKey::Num4: return "Num4";
	case EKey::Num5: return "Num5";
	case EKey::Num6: return "Num6";
	case EKey::Num7: return "Num7";
	case EKey::Num8: return "Num8";
	case EKey::Num9: return "Num9";

		// Function keys
	case EKey::F1: return "F1";
	case EKey::F2: return "F2";
	case EKey::F3: return "F3";
	case EKey::F4: return "F4";
	case EKey::F5: return "F5";
	case EKey::F6: return "F6";
	case EKey::F7: return "F7";
	case EKey::F8: return "F8";
	case EKey::F9: return "F9";
	case EKey::F10: return "F10";
	case EKey::F11: return "F11";
	case EKey::F12: return "F12";

		// Arrows
	case EKey::ArrowUp: return "ArrowUp";
	case EKey::ArrowDown: return "ArrowDown";
	case EKey::ArrowLeft: return "ArrowLeft";
	case EKey::ArrowRight: return "ArrowRight";

		// Control keys
	case EKey::Escape: return "Escape";
	case EKey::Tab: return "Tab";
	case EKey::CapsLock: return "CapsLock";
	case EKey::LeftShift: return "LeftShift";
	case EKey::RightShift: return "RightShift";
	case EKey::LeftCtrl: return "LeftCtrl";
	case EKey::RightCtrl: return "RightCtrl";
	case EKey::LeftAlt: return "LeftAlt";
	case EKey::RightAlt: return "RightAlt";
	case EKey::Space: return "Space";
	case EKey::Enter: return "Enter";
	case EKey::Backspace: return "Backspace";

		// Symbols
	case EKey::Minus: return "Minus";
	case EKey::Equal: return "Equal";
	case EKey::LeftBracket: return "LeftBracket";
	case EKey::RightBracket: return "RightBracket";
	case EKey::Backslash: return "Backslash";
	case EKey::Semicolon: return "Semicolon";
	case EKey::Apostrophe: return "Apostrophe";
	case EKey::Comma: return "Comma";
	case EKey::Period: return "Period";
	case EKey::Slash: return "Slash";

		// Numpad
	case EKey::Numpad0: return "Numpad0";
	case EKey::Numpad1: return "Numpad1";
	case EKey::Numpad2: return "Numpad2";
	case EKey::Numpad3: return "Numpad3";
	case EKey::Numpad4: return "Numpad4";
	case EKey::Numpad5: return "Numpad5";
	case EKey::Numpad6: return "Numpad6";
	case EKey::Numpad7: return "Numpad7";
	case EKey::Numpad8: return "Numpad8";
	case EKey::Numpad9: return "Numpad9";
	case EKey::NumpadAdd: return "NumpadAdd";
	case EKey::NumpadSubtract: return "NumpadSubtract";
	case EKey::NumpadMultiply: return "NumpadMultiply";
	case EKey::NumpadDivide: return "NumpadDivide";
	case EKey::NumpadEnter: return "NumpadEnter";
	case EKey::NumpadDecimal: return "NumpadDecimal";

		// Mouse
	case EKey::MouseLeft: return "MouseLeft";
	case EKey::MouseRight: return "MouseRight";
	case EKey::MouseMiddle: return "MouseMiddle";
	case EKey::MouseButton1: return "MouseX1";
	case EKey::MouseButton2: return "MouseX2";
	case EKey::MouseWheelUp: return "MouseWheelUp";
	case EKey::MouseWheelDown: return "MouseWheelDown";

		// Other
	case EKey::PrintScreen: return "PrintScreen";
	case EKey::ScrollLock: return "ScrollLock";
	case EKey::PauseBreak: return "PauseBreak";
	case EKey::Insert: return "Insert";
	case EKey::Delete: return "Delete";
	case EKey::Home: return "Home";
	case EKey::End: return "End";
	case EKey::PageUp: return "PageUp";
	case EKey::PageDown: return "PageDown";

		// Special
	case EKey::Unknown: return "Unknown";
	case EKey::COUNT: return "COUNT";
	}

	return "Invalid";
}
