#pragma once

#include "DLog.h"
#include "InputAction.h"
#include <memory>

class InputManager;

class InputTrigger
{
public:

	virtual ~InputTrigger() = default;

	[[nodiscard]] virtual bool Evaluate(InputActionValue actionValue, float deltaSeconds) = 0;

	virtual void Reset() {};
};

#pragma region HoldTrigger

class Hold : public InputTrigger
{
public:

	Hold(float durationSeconds);

	[[nodiscard]] virtual bool Evaluate(InputActionValue actionValue, float deltaSeconds) override;
	
	virtual void Reset() override;

protected:

	const float mHoldDuration;
	float mElapsedTime = 0.0f;
};

#pragma endregion

#pragma region ChordActionTrigger

class ChordAction : public InputTrigger
{
public:

	ChordAction(const std::shared_ptr<const InputAction>& action, float maxTimeSinceChordActionActive);

	[[nodiscard]] virtual bool Evaluate(InputActionValue actionValue, float deltaSeconds) override;

protected:

	std::shared_ptr<const InputAction> mChordAction;
	const float mMaxTimeSinceChordActionActive;
	float mElapsedTime = 0.0f;
	bool mWasChordActionActive = false;
};

#pragma endregion

#pragma region TapTrigger

class Tap : public InputTrigger
{
public:

	Tap(float maxHoldTimeSeconds);

	[[nodiscard]] virtual bool Evaluate(InputActionValue actionValue, float deltaSeconds) override;

	virtual void Reset() override;

protected:

	const float mMaxHoldTime;
	float mElapsedTime = 0.0f;
	bool mReleasePending = false;
};

#pragma endregion

namespace Triggers
{
	inline std::unique_ptr<InputTrigger> Hold(float durationSeconds)
	{
		return std::make_unique<::Hold>(durationSeconds);
	}

	inline std::unique_ptr<InputTrigger> ChordAction(const std::shared_ptr<const InputAction>& action, float maxTimeSinceChordActionActive = 0.0f)
	{
		if (!action)
		{
			DLog::Error("Attempting to create a ChordAction trigger with a NULL action.");
			return nullptr;
		}
		return std::make_unique<::ChordAction>(action, maxTimeSinceChordActionActive);
	}

	inline std::unique_ptr<InputTrigger> Tap(float maxHoldTimeSeconds = 0.15f)
	{
		return std::make_unique<::Tap>(maxHoldTimeSeconds);
	}
}