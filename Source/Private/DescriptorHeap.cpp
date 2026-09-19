#include "DescriptorHeap.h"
#include "Device.h"
#include "DxUtil.h"
#include "Types.h"
#include <algorithm>
#include <d3d12.h>
#include <d3dx12.h>
#include <format>
#include <memory>
#include <mutex>
#include <numeric>
#include <stdexcept>
#include <Windows.h>

[[nodiscard]] static constexpr D3D12_DESCRIPTOR_HEAP_TYPE GetDxHeapType(EDescriptorHeapType type)
{
	switch (type)
	{
	case EDescriptorHeapType::General:
	case EDescriptorHeapType::GeneralGPUVisible:
		return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;

	case EDescriptorHeapType::Sampler:
	case EDescriptorHeapType::SamplerGPUVisible:
		return D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;

	case EDescriptorHeapType::RenderTarget:
		return D3D12_DESCRIPTOR_HEAP_TYPE_RTV;

	case EDescriptorHeapType::DepthStencil:
		return D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
	}

	[[unlikely]] throw std::runtime_error("Invalid descriptor heap type");
}

[[nodiscard]] static constexpr bool IsShaderVisible(EDescriptorHeapType type)
{
	if (type == EDescriptorHeapType::GeneralGPUVisible || type == EDescriptorHeapType::SamplerGPUVisible)
	{
		return true;
	}

	return false;
}

#pragma region DescriptorHeap

DescriptorHeap::DescriptorHeap(const Device& device, EDescriptorHeapType type, uint32 numDescriptors)
	:
	mType(type),
	mNumDescriptors(numDescriptors),
	mDescriptorSize(device.GetDxDevice()->GetDescriptorHandleIncrementSize(GetDxHeapType(type))),
	mShaderVisible(IsShaderVisible(type))
{
	D3D12_DESCRIPTOR_HEAP_DESC heapDesc{
		.Type = GetDxHeapType(type),
		.NumDescriptors = numDescriptors,
		.Flags = mShaderVisible ? D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE : D3D12_DESCRIPTOR_HEAP_FLAG_NONE,
		.NodeMask = 0
	};

	DxCall(device.GetDxDevice()->CreateDescriptorHeap(&heapDesc, IID_PPV_ARGS(&mDxHeap)));

	CPUBaseHandle = CD3DX12_CPU_DESCRIPTOR_HANDLE(mDxHeap->GetCPUDescriptorHandleForHeapStart());
	
	if (mShaderVisible)
	{
		GPUBaseHandle = CD3DX12_GPU_DESCRIPTOR_HANDLE(mDxHeap->GetGPUDescriptorHandleForHeapStart());
	}

	mFreeSlots.resize(numDescriptors);
	std::iota(mFreeSlots.rbegin(), mFreeSlots.rend(), 0);
}

HeapHandle DescriptorHeap::AllocateSlot()
{
	std::lock_guard lock(mMutex);

	ensure(!mFreeSlots.empty());

	const uint32 freeSlot = mFreeSlots.back();
	mFreeSlots.pop_back();

	return HeapHandle{
		.CPUHandle = GetCPUSlotHandle(freeSlot),
		.GPUHandle = mShaderVisible ? GetGPUSlotHandle(freeSlot) : D3D12_GPU_DESCRIPTOR_HANDLE{0}
	};
}

void DescriptorHeap::FreeSlot(D3D12_CPU_DESCRIPTOR_HANDLE handle)
{
	std::lock_guard lock(mMutex);

	const uint32 slotIndex = static_cast<uint32>((handle.ptr - CPUBaseHandle.ptr) / mDescriptorSize);

	ensure(slotIndex < mNumDescriptors);
	ensure(std::find(mFreeSlots.begin(), mFreeSlots.end(), slotIndex) == mFreeSlots.end());

	mFreeSlots.push_back(slotIndex);
}

#pragma endregion

#pragma region DescriptorHeapManager

DescriptorHeapManager::DescriptorHeapManager(Device& device)
	:
	mParentDevice(device)
{
}

void DescriptorHeapManager::AllocateDescriptorHeap(EDescriptorHeapType type, uint32 numDescriptors)
{
	const std::size_t heapIndex = static_cast<std::size_t>(type);

	ensure(heapIndex < mHeaps.size());
	ensure(!mHeaps[heapIndex]);

	mHeaps[heapIndex] = std::make_unique<DescriptorHeap>(mParentDevice, type, numDescriptors);
}

DescriptorHeap& DescriptorHeapManager::GetDescriptorHeap(EDescriptorHeapType type) const
{
	const std::size_t heapIndex = static_cast<std::size_t>(type);

	ensure(heapIndex < mHeaps.size());
	ensure(mHeaps[heapIndex]);

	return *mHeaps[heapIndex];
}

HeapHandle DescriptorHeapManager::AllocateHeapSlot(EDescriptorHeapType type) const
{
	return GetDescriptorHeap(type).AllocateSlot();
}

void DescriptorHeapManager::FreeHeapSlot(EDescriptorHeapType type, D3D12_CPU_DESCRIPTOR_HANDLE handle) const
{
	GetDescriptorHeap(type).FreeSlot(handle);
}

#pragma endregion