#include "App.h"
#include "InputManager.h"
#include "InputTrigger.h"
#include <InputAction.h>
#include <memory>

#pragma region HoldTrigger

Hold::Hold(float durationSeconds)
	:
	mHoldDuration(durationSeconds)
{}

bool Hold::Evaluate(InputActionValue actionValue, float deltaSeconds)
{
	if (actionValue.IsNonZero())
	{
		mElapsedTime += deltaSeconds;
		return mElapsedTime >= mHoldDuration;
	}

	mElapsedTime = 0.0f;
	return false;
}

void Hold::Reset()
{
	mElapsedTime = 0.0f;
}

#pragma endregion

#pragma region ChordActionTrigger

ChordAction::ChordAction(const std::shared_ptr<const InputAction>& action, float maxTimeSinceChordActionActive)
	:
	mChordAction(action),
	mMaxTimeSinceChordActionActive(maxTimeSinceChordActionActive)
{}

bool ChordAction::Evaluate([[maybe_unused]] InputActionValue actionValue, [[maybe_unused]] float deltaSeconds)
{
	bool chordActionActive = App::Get().GetInputManager().IsInputActionActive(mChordAction);

	if (mMaxTimeSinceChordActionActive <= 0.0f)
	{
		return chordActionActive;
	}	

	if (chordActionActive)
	{
		mWasChordActionActive = true;
		mElapsedTime = 0.0f;
		return true;
	}
	else if (mWasChordActionActive)
	{
		mElapsedTime += deltaSeconds;
		if (mElapsedTime <= mMaxTimeSinceChordActionActive)
		{
			return true;
		}
		else
		{
			mWasChordActionActive = false;
			mElapsedTime = 0.0f;
			return false;
		}
	}

	return false;	
}

#pragma endregion

#pragma region TapTrigger

Tap::Tap(float maxHoldTimeSeconds)
	:
	mMaxHoldTime(maxHoldTimeSeconds)
{}

bool Tap::Evaluate(InputActionValue actionValue, float deltaSeconds)
{
	if (mReleasePending)
	{
		if (actionValue.IsNonZero())
		{
			mElapsedTime += deltaSeconds;
		}
		else // Released
		{			
			const bool releasedOnTime = mElapsedTime <= mMaxHoldTime;
			mElapsedTime = 0.0f;
			mReleasePending = false;

			return releasedOnTime;
		}
	}
	else if (actionValue.IsNonZero())
	{
		mReleasePending = true;
	}
	return false;
}

void Tap::Reset()
{
	mElapsedTime = 0.0f;
	mReleasePending = false;
}

#pragma endregion
