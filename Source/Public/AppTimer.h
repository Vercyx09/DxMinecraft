#pragma once
#include "Types.h"

class AppTimer
{

public:

	AppTimer();

	void Tick();

	void Pause();

	void Start();

	void Reset();

	float DeltaSeconds() const;

	float TotalSeconds() const;

private:

	bool mPaused;

	double mSecondsPerCount;
	double mDeltaSeconds;

	int64 mCurrentCountStamp;
	int64 mPreviousCountStamp;
	int64 mPausedCountStamp;
	int64 mPausedCount;
	int64 mBaseCountStamp;
};

