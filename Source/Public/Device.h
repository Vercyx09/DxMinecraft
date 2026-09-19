#pragma once
#include "Core.h"
#include "DxUtil.h"
#include "Types.h"
#include <d3d12.h>
#include <memory>
#include <mutex>
#include <vector>
#include <Windows.h>
#include <wrl/client.h>


template <EQueryHeapType HeapType>
class QueryHeap;
class CommandContext;
class DescriptorHeap;
class DescriptorHeapManager;

class Device
{
public:

	Device(Microsoft::WRL::ComPtr<ID3D12Device>&& dxDevice);

	Device(ID3D12Device*) = delete;

	Device(const Device&) = delete;
	Device(Device&&) = delete;
	Device& operator=(const Device&) = delete;
	Device& operator=(Device&&) = delete;
	
	~Device();

public:

	[[nodiscard]] FORCEINLINE ID3D12Device* GetDxDevice() const noexcept { return mDxDevice.Get(); }

	[[nodiscard]] FORCEINLINE ID3D12CommandQueue* GetDxDirectQueue() const noexcept { return mDxDirectQueue.Get(); }

	[[nodiscard]] FORCEINLINE DescriptorHeapManager& GetDescriptorHeapManager() const noexcept { return *mDescriptorHeapManager.get(); }

	[[nodiscard]] FORCEINLINE uint64 GetCurrentFenceValue() const noexcept { return mCurrentFenceValue; }

	[[nodiscard]] FORCEINLINE uint64 GetCompletedFenceValue() const { return mDxFence->GetCompletedValue(); }

public:

	[[nodiscard]] std::unique_ptr<CommandContext> ObtainCommandContext();

	[[nodiscard]] std::unique_ptr<CommandContext>& GetDirectContext() { return mDirectContext; }

	void SubmitCommandContext(std::unique_ptr<CommandContext>& context);

	void ReleaseCommandContext(std::unique_ptr<CommandContext>&& context);

	[[nodiscard]] float GetFrameTime(uint64 index);

	[[nodiscard]] ID3D12QueryHeap* GetDxQueryHeap();

	[[nodiscard]] ID3D12Resource* GetDxQueryBuffer();

public:

	void FlushCommandQueue();

	void SetFenceEvent(uint64 fenceValue, HANDLE eventHandle);

	void SignalFence();

protected:

	void CreateDescriptorHeaps();

	void CreateQueryHeaps();

protected:

	using TimestampQueryHeap = QueryHeap<EQueryHeapType::Timestamp>;

	Microsoft::WRL::ComPtr<ID3D12Device> mDxDevice;

	Microsoft::WRL::ComPtr<ID3D12Fence> mDxFence;
	uint64 mCurrentFenceValue = 0;

	Microsoft::WRL::ComPtr<ID3D12CommandQueue> mDxDirectQueue;

	std::unique_ptr<DescriptorHeapManager> mDescriptorHeapManager;

	std::vector<std::unique_ptr<CommandContext>> mContextPool;

	std::unique_ptr<CommandContext> mDirectContext;

	std::unique_ptr<TimestampQueryHeap> mTimestampHeap;

	std::mutex mContextPoolMutex;

	uint64 mDirectQueueFrequency = 0;
};