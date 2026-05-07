#include "InputAction.h"
#include <string>


InputAction::InputAction(const std::string& name, EActionValueType valueType)
	:
	mName(name),
	mValueType(valueType)
{
}

void InputAction::Invoke(EActionState state, InputActionValue value, float deltaSeconds) const
{
	const auto& callbacks = mCallbacks[static_cast<std::size_t>(state)];

	for (const auto& callback : callbacks)
	{
		callback(value, deltaSeconds);
	}
}