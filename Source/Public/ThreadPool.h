#pragma once
#include "Types.h"
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <stop_token>
#include <thread>
#include <utility>
#include <vector>

class ThreadPool
{
public:

	ThreadPool(uint32 numThreads);

	~ThreadPool();

	ThreadPool(const ThreadPool&)= delete;
	ThreadPool& operator=(const ThreadPool&) = delete;
	ThreadPool(ThreadPool&&) = delete;
	ThreadPool& operator=(ThreadPool&&) = delete;


public:

	void Shutdown();

	template<typename T>
	void EnqueueTask(T&& task)
	{
		{
			std::lock_guard lock{ mMutex };
			mTasks.emplace(std::forward<T>(task));
		}
		mConditionVariable.notify_one();
	}

protected:

	void ThreadLoop(std::stop_token token);

protected:

	std::vector<std::jthread> mThreads;
	std::queue<std::function<void()>> mTasks;

	std::mutex mMutex;
	std::condition_variable mConditionVariable;
};


//inline ThreadPool gThreadPool = ThreadPool(std::thread::hardware_concurrency() - 1);
//inline ThreadPool gThreadPool = ThreadPool(1);