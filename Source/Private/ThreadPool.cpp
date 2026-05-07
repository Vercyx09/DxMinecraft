#pragma once
#include "DxUtil.h"
#include "DLog.h"
#include "ThreadPool.h"
#include "Types.h"
#include <functional>
#include <mutex>
#include <queue>
#include <stop_token>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <Windows.h>

ThreadPool::ThreadPool(uint32 numThreads)
{
	mThreads.reserve(numThreads);
	for (uint32 i = 0; i < numThreads; i++)
	{
		mThreads.emplace_back([this](std::stop_token token) { ThreadLoop(token); } );
		std::wstring threadName = L"Thread Pool Worker Thread " + std::to_wstring(i);
		HRESULT hr = SetThreadDescription(mThreads.back().native_handle(), threadName.data());
		ensure(SUCCEEDED(hr));
	}
}

ThreadPool::~ThreadPool()
{
	for (auto& thread : mThreads)
	{
		thread.request_stop();
	}
	mConditionVariable.notify_all();
	for (auto& thread : mThreads)
	{
		thread.join();
	}
}

void ThreadPool::ThreadLoop(std::stop_token token)
{
	std::function<void()> task;
	while (!token.stop_requested())
	{
		{
			std::unique_lock lock{ mMutex };
			mConditionVariable.wait(lock, [this, &token]() { return token.stop_requested() || !mTasks.empty(); });

			if (token.stop_requested() && mTasks.empty())
			{
				return;
			}

			task = std::move(mTasks.front());
			mTasks.pop();
		}
		task();
	}
}
