#include "Device.h"
#include "DxUtil.h"
#include "RenderResource.h"
#include "ResourceView.h"
#include <CommandContext.h>
#include <d3d12.h>
#include <d3dx12.h>
#include <DDSTextureLoader12.h>
#include <dxgiformat.h>
#include <memory>
#include <string.h>
#include <string_view>
#include <Types.h>
#include <utility>
#include <vector>
#include <Windows.h>
#include <wrl/client.h>

#pragma region Texture

Texture::Texture(Device& device, const TextureDesc& textureDesc)
{
	CD3DX12_HEAP_PROPERTIES heapProperties(D3D12_HEAP_TYPE_DEFAULT); // GPU-only memory

	DxCall(device.GetDxDevice()->CreateCommittedResource(
		&heapProperties,
		D3D12_HEAP_FLAG_NONE,
		textureDesc.GetResourceDesc(),
		mResourceState,
		textureDesc.GetOptimizedClearValue(),
		IID_PPV_ARGS(&mDxResource)
	));
}

Texture::Texture(Microsoft::WRL::ComPtr<ID3D12Resource>&& dxResource)
{
	ensure(dxResource);
	mDxResource = std::move(dxResource);
}


std::unique_ptr<Texture> Texture::CreateFromFile(std::wstring_view fileName, Device& device, CommandContext* context, bool createSRV)
{
	ID3D12Device* dxDevice = device.GetDxDevice();
	const wchar_t* texturePath = fileName.data();
	Microsoft::WRL::ComPtr<ID3D12Resource> textureResource;
	std::vector<D3D12_SUBRESOURCE_DATA> subresources;
	std::unique_ptr<uint8[]> data;

	DxCall(DirectX::LoadDDSTextureFromFile(
		dxDevice,
		texturePath,
		textureResource.GetAddressOf(),
		data,
		subresources
	));

	D3D12_RESOURCE_DESC resourceDesc = textureResource->GetDesc();

	std::unique_ptr<Texture> texture = std::make_unique<Texture>(std::move(textureResource));
	texture->UpdateTextureData(context, subresources);

	if (createSRV)
	{
		// TODO: maybe make this more robust
		D3D12_SRV_DIMENSION viewDimension = resourceDesc.DepthOrArraySize > 1 ? D3D12_SRV_DIMENSION_TEXTURE2DARRAY : D3D12_SRV_DIMENSION_TEXTURE2D;

		D3D12_SHADER_RESOURCE_VIEW_DESC viewDesc{
			.Format = resourceDesc.Format,
			.ViewDimension = viewDimension, 
			.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING,
			.Texture2DArray = {
				.MostDetailedMip = 0,
				.MipLevels = resourceDesc.MipLevels,
				.FirstArraySlice = 0,
				.ArraySize = resourceDesc.DepthOrArraySize,
				.PlaneSlice = 0,
				.ResourceMinLODClamp = 0.0f
			}
		};

		texture->CreateShaderResourceView(device, viewDesc);
	}

	return texture;
}

std::unique_ptr<Texture> Texture::CreateFromFile(std::wstring_view fileName, Device& device, bool createSRV)
{
	return CreateFromFile(fileName, device, device.GetDirectContext().get(), createSRV);
}

void Texture::UpdateTextureData(CommandContext* context, std::span<D3D12_SUBRESOURCE_DATA> subresourceData)
{
	ensure(mDxResource); // Make sure we already have a resource in the default heap

	ID3D12GraphicsCommandList* dxCommandList = context->GetDxCommandList();

	//const UINT num2DSubresources = texDesc.DepthOrArraySize * texDesc.MipLevels;
	const uint32 num2DSubresources = static_cast<uint32>(subresourceData.size());
	const uint64 uploadBufferSize = GetRequiredIntermediateSize(mDxResource.Get(), 0, num2DSubresources);


	// Allocate CPU accessible memory for the upload
	mResourceLocation = context->GetUploadAllocator().Allocate(uploadBufferSize, 16);

	auto copyDestBarrier = CD3DX12_RESOURCE_BARRIER::Transition(
		mDxResource.Get(),
		D3D12_RESOURCE_STATE_COMMON,
		D3D12_RESOURCE_STATE_COPY_DEST
	);

	dxCommandList->ResourceBarrier(1, &copyDestBarrier);

	UpdateSubresources(
		dxCommandList,
		mDxResource.Get(),
		mResourceLocation.Resource,
		mResourceLocation.Offset,
		0,
		static_cast<uint32>(subresourceData.size()),
		subresourceData.data()
	);

	auto PSBarrier = CD3DX12_RESOURCE_BARRIER::Transition(
		mDxResource.Get(),
		D3D12_RESOURCE_STATE_COPY_DEST,
		D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE
	);

	dxCommandList->ResourceBarrier(1, &PSBarrier);
}

void Texture::CreateShaderResourceView(Device& device, const D3D12_SHADER_RESOURCE_VIEW_DESC& desc)
{
	ensure(!mShaderResourceView);
	mShaderResourceView = std::make_unique<ShaderResourceView>(device, mDxResource.Get(), desc, true); // TODO maybe have option for non-shader visible SRV?
}

void Texture::CreateRenderTargetView(Device& device, const D3D12_RENDER_TARGET_VIEW_DESC& desc)
{
	ensure(!mRenderTargetView);
	mRenderTargetView = std::make_unique<RenderTargetView>(device, mDxResource.Get(), desc);
}

void Texture::CreateDepthStencilView(Device& device, const D3D12_DEPTH_STENCIL_VIEW_DESC& desc)
{
	ensure(!mDepthStencilView);
	mDepthStencilView = std::make_unique<DepthStencilView>(device, mDxResource.Get(), desc);
}

#pragma endregion

#pragma region DefaultBuffer

DefaultBuffer::DefaultBuffer(Device& device, std::size_t byteSize)
{
	ID3D12Device* dxDevice = device.GetDxDevice();
	CD3DX12_HEAP_PROPERTIES heapProperties = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT);
	CD3DX12_RESOURCE_DESC resourceDesc = CD3DX12_RESOURCE_DESC::Buffer(byteSize);

	DxCall(dxDevice->CreateCommittedResource(
		&heapProperties,
		D3D12_HEAP_FLAG_NONE,
		&resourceDesc,
		D3D12_RESOURCE_STATE_COMMON,
		nullptr,
		IID_PPV_ARGS(&mDxResource)
	));
}

void DefaultBuffer::UploadBufferData(CommandContext* context, const void* data, std::size_t dataByteSize, D3D12_RESOURCE_STATES finalState)
{
	ensure(context);
	ensure(dataByteSize == mDxResource->GetDesc().Width);

	ID3D12GraphicsCommandList* dxCommandList = context->GetDxCommandList();

	// Allocate CPU accessible memory for the upload
	mResourceLocation = context->GetUploadAllocator().Allocate(dataByteSize, 16);

	// Copy data to the allocated CPU accesible memory
	memcpy(mResourceLocation.CPU, data, dataByteSize);

	auto commonToCopyDestTransition = CD3DX12_RESOURCE_BARRIER::Transition(
		mDxResource.Get(),
		D3D12_RESOURCE_STATE_COMMON,
		D3D12_RESOURCE_STATE_COPY_DEST
	);
	dxCommandList->ResourceBarrier(1, &commonToCopyDestTransition);

	// Schedule a copy from the CPU accessible memory to the GPU buffer
	dxCommandList->CopyBufferRegion(
		mDxResource.Get(),
		0,
		mResourceLocation.Resource,
		mResourceLocation.Offset,
		dataByteSize
	);

	auto copyDestToFinalTransition = CD3DX12_RESOURCE_BARRIER::Transition(
		mDxResource.Get(),
		D3D12_RESOURCE_STATE_COPY_DEST,
		finalState
	);

	dxCommandList->ResourceBarrier(1, &copyDestToFinalTransition);
}

#pragma endregion

#pragma region VertexBuffer

VertexBuffer::VertexBuffer(Device& device, std::size_t byteSize, uint32 byteStride)
	:
	DefaultBuffer(device, byteSize),
	mByteStride(byteStride)
{}

D3D12_VERTEX_BUFFER_VIEW VertexBuffer::GetVertexBufferView() const noexcept
{
	return D3D12_VERTEX_BUFFER_VIEW{
		.BufferLocation = mDxResource->GetGPUVirtualAddress(),
		.SizeInBytes = static_cast<uint32>(mResourceLocation.Size),
		.StrideInBytes = mByteStride
	};
}

#pragma endregion


#pragma region IndexBuffer

IndexBuffer::IndexBuffer(Device& device, std::size_t byteSize, DXGI_FORMAT indexFormat)
	:
	DefaultBuffer(device, byteSize),
	mIndexFormat(indexFormat)
{}

D3D12_INDEX_BUFFER_VIEW IndexBuffer::GetIndexBufferView() const noexcept
{
	return D3D12_INDEX_BUFFER_VIEW{
		.BufferLocation = mDxResource->GetGPUVirtualAddress(),
		.SizeInBytes = static_cast<uint32>(mResourceLocation.Size),
		.Format = mIndexFormat
	};
}

#pragma endregion

#pragma region ConstantBuffer

ConstantBuffer::ConstantBuffer(Device& device, uint32 elementCount, uint32 elementByteSize)
	:
	mElementByteSize(DxUtil::GetConstBufferSize(elementByteSize))
{
	CD3DX12_HEAP_PROPERTIES heapProperties = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	CD3DX12_RESOURCE_DESC resourceDesc = CD3DX12_RESOURCE_DESC::Buffer(mElementByteSize * elementCount);

	DxCall(device.GetDxDevice()->CreateCommittedResource(
		&heapProperties,
		D3D12_HEAP_FLAG_NONE,
		&resourceDesc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&mDxResource)
	));

	mResourceLocation.Resource = mDxResource.Get();
	mResourceLocation.Offset = 0;
	mResourceLocation.GPU = mDxResource->GetGPUVirtualAddress();

	DxCall(mDxResource->Map(0, nullptr, &mResourceLocation.CPU));

	D3D12_CONSTANT_BUFFER_VIEW_DESC viewDesc{
		.BufferLocation = mResourceLocation.GPU,
		.SizeInBytes = static_cast<uint32>(mElementByteSize)
	};

	mConstantBufferView = std::make_unique<ConstantBufferView>(device, viewDesc, true); // TODO maybe have option for non-shader visible CBV?
}

ConstantBuffer::~ConstantBuffer()
{
	if (mDxResource)
	{
		mDxResource->Unmap(0, nullptr);
	}
}

void ConstantBuffer::UpdateBufferData(const void* data, std::size_t size)
{
	memcpy(mResourceLocation.CPU, data, size);
}

#pragma endregion
