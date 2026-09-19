#include "AppTimer.h"
#include "Types.h"
#include "Windows.h"

AppTimer::AppTimer()
	:
	mBaseCountStamp(0),
	mPreviousCountStamp(0),
	mCurrentCountStamp(0),
	mPausedCountStamp(0),
	mPausedCount(0),
	mDeltaSeconds(0.0),
	mPaused(false)
{
	int64 countsPerSecond = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)(&countsPerSecond));

	mSecondsPerCount = 1.0 / countsPerSecond;
}

void AppTimer::Tick()
{
	if (mPaused)
	{
		mDeltaSeconds = 0.0;
		return;
	}

	mPreviousCountStamp = mCurrentCountStamp;
	QueryPerformanceCounter((LARGE_INTEGER*)(&mCurrentCountStamp));

	mDeltaSeconds = (mCurrentCountStamp - mPreviousCountStamp) * mSecondsPerCount;
	if (mDeltaSeconds < 0.0)
	{
		mDeltaSeconds = 0.0;
	}
}

void AppTimer::Pause()
{
	int64 currentCount = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)(&currentCount));

	if (!mPaused)
	{
		mPaused = true;
		mPausedCountStamp = currentCount;
	}
}

void AppTimer::Start()
{
	int64 currentCount = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)(&currentCount));

	if (mPaused)
	{
		mPaused = false;
		mPausedCount += currentCount - mPausedCountStamp;
		mPausedCountStamp = 0;
		mPreviousCountStamp = currentCount;
	}
}

void AppTimer::Reset()
{
	int64 currentCount = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)(&currentCount));

	mBaseCountStamp = currentCount;
	mPreviousCountStamp = currentCount;
	mCurrentCountStamp = currentCount;
	mPausedCountStamp = 0;
	
	mDeltaSeconds = 0.0;

	mPaused = false;
}

float AppTimer::DeltaSeconds() const
{
	return static_cast<float>(mDeltaSeconds);
}

float AppTimer::TotalSeconds() const
{
	if (mPaused)
	{
		return static_cast<float>(((mPausedCountStamp - mBaseCountStamp) - mPausedCount) * mSecondsPerCount);
	}
	
	return static_cast<float>(((mCurrentCountStamp - mBaseCountStamp) - mPausedCount) * mSecondsPerCount);
}
