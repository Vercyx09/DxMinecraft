#pragma once
#include "Core.h"
#include "UploadAllocator.h"
#include <d3d12.h>
#include <queue>
#include <unordered_map>
#include <wrl/client.h>

class RenderResource;
class Device;


struct ResourceBarrier
{
	RenderResource* resource;
	D3D12_RESOURCE_STATES stateBefore;
	D3D12_RESOURCE_STATES stateAfter;
};


class CommandContext
{
public:

	CommandContext(Device& device);

	~CommandContext();

public:

	void Reset(ID3D12PipelineState* pso = nullptr);

	void Close();

public:

	[[nodiscard]] FORCEINLINE ID3D12GraphicsCommandList* GetDxCommandList() const noexcept { return mDxCommandList.Get(); }

	[[nodiscard]] FORCEINLINE UploadAllocator& GetUploadAllocator() noexcept { return mUploadAllocator; }

	[[nodiscard]] FORCEINLINE Device& GetDevice() noexcept { return mParentDevice; }

protected:

	Device& mParentDevice;

	UploadAllocator mUploadAllocator;

	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> mDxCommandList;

	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> mDxCommandAllocator;

	std::unordered_map<RenderResource*, D3D12_RESOURCE_STATES> mResourceStateMap;

	std::queue<ResourceBarrier> mPendingResourceBarriers;

	bool mIsClosed = false;
};