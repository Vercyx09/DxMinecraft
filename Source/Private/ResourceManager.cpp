#include "ResourceManager.h"
#include "Types.h"
#include <algorithm>
#include <memory>
#include <mutex>
#include <utility>
#include <vector>

ResourceManager::~ResourceManager()
{
	std::scoped_lock lock(mMutex);
	mPendingDeletes.clear(); // unique_ptr will release all resources
}

void ResourceManager::AddPendingDelete(std::unique_ptr<RenderResource> resource, uint64 fence)
{
	std::scoped_lock lock(mMutex);

	auto it = std::upper_bound(
		mPendingDeletes.begin(),
		mPendingDeletes.end(),
		fence,
		[](uint64 f, const PendingDelete& pendingDelete)
		{
			return f > pendingDelete.fence; // descending order
		}
	);

	mPendingDeletes.emplace(it, std::move(resource), fence);
}

void ResourceManager::ProcessPendingDeletes(uint64 fenceValue)
{
	std::vector<PendingDelete> remaining;

	std::scoped_lock lock(mMutex);
	for (auto& pd : mPendingDeletes)
	{
		if (pd.fence > fenceValue)
		{
			remaining.push_back(std::move(pd));
		}
		// else: let unique_ptr go out of scope and delete the resource
	}
	mPendingDeletes = std::move(remaining);
}
