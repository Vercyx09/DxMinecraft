#include "BindingContext.h"
#include "DLog.h"
#include "InputModifier.h"
#include <algorithm>
#include <string>

std::span<const BindingContext::Binding> BindingContext::GetBindingsForKey(EKey key) const
{
	if (mKeyActionsMap.contains(key))
	{
		return mKeyActionsMap.at(key);
	}

	return {};
}

const InputAction* BindingContext::GetAction(ActionHandle handle) const
{
	if (handle >= mActions.size())
	{
		DLog::Warn("Invalid ActionHandle passed to BindingContext::GetAction()");
		return nullptr;
	}

	return mActions[handle].get();
}

void BindingContext::AddActionMapping(ActionMapping&& actionMapping)
{
	if (auto it = std::ranges::find(mActions, actionMapping.action); it != mActions.end())
	{
		DLog::Warn("Attempting to add a duplicate InputAction {} to the BindingContext {}, the mapping will be ignored.");
		return;
	}

	ActionHandle actionHandle = mActions.size();
	mActions.push_back(actionMapping.action);

	for (auto& mapping : actionMapping.mappings)
	{
		mKeyActionsMap[mapping.key].emplace_back(
			actionHandle,
			std::move(mapping.modifiers),
			std::move(mapping.triggers),
			mapping.key
		);
	}
}

std::string ToString(EKey key)
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

        // Control
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
    case EKey::MouseButton1: return "MouseButton1";
    case EKey::MouseButton2: return "MouseButton2";
    case EKey::MouseX: return "MouseX";
    case EKey::MouseY: return "MouseY";
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

    default: return "Invalid";
    }
}
