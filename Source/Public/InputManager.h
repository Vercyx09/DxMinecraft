#pragma once
#include "BindingContext.h"
#include "InputAction.h"
#include "Types.h"
#include <array>
#include <memory>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

#define KEY_COUNT static_cast<std::size_t>(EKey::COUNT)

class InputModifier;
class InputTrigger;


std::string GetStringForKey(EKey key);


struct BindingState
{
	BindingState(const BindingContext::Binding& binding, EActionState state = EActionState::Ongoing)
		:
		binding(binding),
		state(state)
	{}

	std::reference_wrapper<const BindingContext::Binding> binding;
	EActionState state;
};

struct KeyEvent
{
	EKey key;
	float value;
};

struct ContextPriority
{
	std::shared_ptr<const BindingContext> context;
	uint8 priority;
};

class InputManager final
{
public:

	InputManager();

	~InputManager() = default;

	InputManager(const InputManager&) = delete;

	InputManager& operator=(const InputManager&) = delete;

	InputManager(InputManager&&) = delete;

	InputManager& operator=(InputManager&&) = delete;

public:

	void ProcessKeyEvent(KeyEvent event);

	void Update(float deltaSeconds);

	void ActivateContext(const std::shared_ptr<const BindingContext>& context, uint8 priority = 0);

	[[nodiscard]] bool IsInputActionActive(const std::shared_ptr<const InputAction>& action) const;

	void ClearInputs();

	[[nodiscard]] EActionState GetActionStateOfTrigger(InputTrigger* trigger) const;

private:

	[[nodiscard]] static InputActionValue ApplyModifiers(
		InputActionValue value,
		EActionValueType valueType,
		std::span<const std::unique_ptr<const InputModifier>> modifiers
	);

	[[nodiscard]] static bool EvaluateTriggers(
		std::span<const std::unique_ptr<InputTrigger>> triggers,
		const InputActionValue actionValue,
		float deltaSeconds
	);

	static void ResetTriggers(std::span<const std::unique_ptr<InputTrigger>> triggers);


private:

	std::array<float, KEY_COUNT> mKeyValues;

	std::vector<ContextPriority> mActiveContexts;

	std::vector<KeyEvent> mPendingKeyEvents;

	std::unordered_map<const InputAction*, std::vector<BindingState>> mLiveActions; // TODO: change to std::flat_map
};