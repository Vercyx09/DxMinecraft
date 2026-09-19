#pragma once
#include "Core.h"
#include "d3d12.h"
#include "DescriptorHeap.h"
#include "Device.h"
#include "DxUtil.h"


class ResourceView
{
protected:

	ResourceView(Device& device, EDescriptorHeapType heapType)
		:
		mParentDevice(device),
		mHeapType(heapType)
	{
		DescriptorHeapManager& descriptorHeapManager = device.GetDescriptorHeapManager();
		HeapHandle heapHandle = descriptorHeapManager.AllocateHeapSlot(heapType);

		mCPUDescriptorHandle = heapHandle.CPUHandle;
		mGPUDescriptorHandle = heapHandle.GPUHandle;
	}

	~ResourceView()
	{
		DescriptorHeapManager& descriptorHeapManager = mParentDevice.GetDescriptorHeapManager();
		descriptorHeapManager.FreeHeapSlot(mHeapType, mCPUDescriptorHandle);
	}

	ResourceView(const ResourceView&) = default;

	ResourceView& operator=(const ResourceView&) = default;

	ResourceView(ResourceView&&) = default;

	ResourceView& operator=(ResourceView&&) = default;

public:

	[[nodiscard]] FORCEINLINE D3D12_CPU_DESCRIPTOR_HANDLE GetCPUDescriptorHandle() const noexcept { return mCPUDescriptorHandle; }

	[[nodiscard]] FORCEINLINE D3D12_GPU_DESCRIPTOR_HANDLE GetGPUDescriptorHandle() const noexcept
	{
		ensure(mHeapType == EDescriptorHeapType::GeneralGPUVisible || mHeapType == EDescriptorHeapType::SamplerGPUVisible);
		return mGPUDescriptorHandle;
	}

protected:

	Device& mParentDevice;

	EDescriptorHeapType mHeapType;

	D3D12_CPU_DESCRIPTOR_HANDLE mCPUDescriptorHandle{ 0 };

	D3D12_GPU_DESCRIPTOR_HANDLE mGPUDescriptorHandle{ 0 };
};

class RenderTargetView : public ResourceView
{
public:

	RenderTargetView(Device& device, ID3D12Resource* resource, const D3D12_RENDER_TARGET_VIEW_DESC& desc)
		:
		ResourceView(device, EDescriptorHeapType::RenderTarget)
	{
		device.GetDxDevice()->CreateRenderTargetView(
			resource,
			&desc,
			mCPUDescriptorHandle
		);
	}
};

class DepthStencilView : public ResourceView
{
public:

	DepthStencilView(Device& device, ID3D12Resource* resource, const D3D12_DEPTH_STENCIL_VIEW_DESC& desc)
		:
		ResourceView(device, EDescriptorHeapType::DepthStencil)
	{
		device.GetDxDevice()->CreateDepthStencilView(
			resource,
			&desc,
			mCPUDescriptorHandle
		);
	}
};

class ShaderResourceView : public ResourceView
{
public:

	ShaderResourceView(Device& device, ID3D12Resource* resource, const D3D12_SHADER_RESOURCE_VIEW_DESC& desc, bool shaderVisible)
		:
		ResourceView(device, shaderVisible ? EDescriptorHeapType::GeneralGPUVisible : EDescriptorHeapType::General)
	{
		device.GetDxDevice()->CreateShaderResourceView(
			resource,
			&desc,
			mCPUDescriptorHandle
		);
	}
};

class UnorderedAccessView : public ResourceView
{
public:

	UnorderedAccessView(Device& device, ID3D12Resource* resource, const D3D12_UNORDERED_ACCESS_VIEW_DESC& desc, bool shaderVisible)
		:
		ResourceView(device, shaderVisible ? EDescriptorHeapType::GeneralGPUVisible : EDescriptorHeapType::General)
	{
		device.GetDxDevice()->CreateUnorderedAccessView(
			resource,
			nullptr,
			&desc,
			mCPUDescriptorHandle
		);
	}
};

class ConstantBufferView : public ResourceView
{
public:

	ConstantBufferView(Device& device, const D3D12_CONSTANT_BUFFER_VIEW_DESC& desc, bool shaderVisible)
		:
		ResourceView(device, shaderVisible ? EDescriptorHeapType::GeneralGPUVisible : EDescriptorHeapType::General)
	{
		device.GetDxDevice()->CreateConstantBufferView(
			&desc,
			mCPUDescriptorHandle
		);
	}
};