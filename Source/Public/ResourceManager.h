#pragma once
#include "RenderResource.h"
#include "Types.h"
#include <memory>
#include <mutex>
#include <vector>


struct PendingDelete
{
	std::unique_ptr<RenderResource> resource;
	uint64 fence;
};

class ResourceManager
{
public:

	ResourceManager() = default;

	~ResourceManager();

	ResourceManager(ResourceManager&) = delete;

	ResourceManager(ResourceManager&&) = delete;

	ResourceManager& operator=(const ResourceManager&) = delete;

	ResourceManager& operator=(ResourceManager&&) = delete;

public:

	void AddPendingDelete(std::unique_ptr<RenderResource> resource, uint64 fence);

	void ProcessPendingDeletes(uint64 fenceValue);

protected:

	std::mutex mMutex;
	std::vector<PendingDelete> mPendingDeletes;	
};