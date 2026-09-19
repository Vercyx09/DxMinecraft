#pragma once
#include "Core.h"
#include "DxUtil.h"
#include "Types.h"
#include <array>
#include <d3d12.h>
#include <d3dx12.h>
#include <memory>
#include <mutex>
#include <vector>
#include <wrl/client.h>


#define DESCRIPTOR_HEAP_TYPE_COUNT static_cast<std::size_t>(EDescriptorHeapType::COUNT)

class Device;

enum class EDescriptorHeapType : uint8
{
	General,	// CBV, SRV, UAV
	Sampler,
	RenderTarget,
	DepthStencil,
	GeneralGPUVisible, // CBV, SRV, UAV
	SamplerGPUVisible,
	COUNT
};


struct HeapHandle
{
	D3D12_CPU_DESCRIPTOR_HANDLE CPUHandle;
	D3D12_GPU_DESCRIPTOR_HANDLE GPUHandle;
};

class DescriptorHeap
{
public:

	DescriptorHeap(const Device& device, EDescriptorHeapType type, uint32 numDescriptors);

public:

	[[nodiscard]] FORCEINLINE ID3D12DescriptorHeap* GetDxHeap() const noexcept { return mDxHeap.Get(); }

	[[nodiscard]] FORCEINLINE D3D12_CPU_DESCRIPTOR_HANDLE GetCPUSlotHandle(uint32 slot) const noexcept
	{
		return CD3DX12_CPU_DESCRIPTOR_HANDLE(CPUBaseHandle, slot, mDescriptorSize);
	}

	[[nodiscard]] FORCEINLINE D3D12_GPU_DESCRIPTOR_HANDLE GetGPUSlotHandle(uint32 slot) const noexcept
	{
		ensure(mShaderVisible);
		return CD3DX12_GPU_DESCRIPTOR_HANDLE(GPUBaseHandle, slot, mDescriptorSize);
	}

	HeapHandle AllocateSlot();

	void FreeSlot(D3D12_CPU_DESCRIPTOR_HANDLE handle);

protected:

	uint32 mNumDescriptors;
	uint32 mDescriptorSize;

	bool mShaderVisible;
	EDescriptorHeapType mType;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> mDxHeap;

	D3D12_CPU_DESCRIPTOR_HANDLE CPUBaseHandle{ 0 };
	D3D12_GPU_DESCRIPTOR_HANDLE GPUBaseHandle{ 0 };

	std::vector<uint32> mFreeSlots;

	std::mutex mMutex;
};


class DescriptorHeapManager
{
public:

	DescriptorHeapManager(Device& device);

public:

	void AllocateDescriptorHeap(EDescriptorHeapType type, uint32 numDescriptors);

	[[nodiscard]] DescriptorHeap& GetDescriptorHeap(EDescriptorHeapType type) const;

	HeapHandle AllocateHeapSlot(EDescriptorHeapType type) const;

	void FreeHeapSlot(EDescriptorHeapType type, D3D12_CPU_DESCRIPTOR_HANDLE handle) const;

protected:

	Device& mParentDevice;

	std::array<std::unique_ptr<DescriptorHeap>, DESCRIPTOR_HEAP_TYPE_COUNT> mHeaps;
};