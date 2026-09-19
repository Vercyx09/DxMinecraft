#pragma once
#include "Core.h"
#include "DxUtil.h"
#include "ResourceView.h"
#include "Types.h"
#include "UploadAllocator.h"
#include <d3d12.h>
#include <dxgiformat.h>
#include <memory>
#include <span>
#include <string_view>
#include <wrl/client.h>

class Device;
class CommandContext;

#pragma region RenderResource

class RenderResource
{
protected:

	RenderResource() = default;

public:

	virtual ~RenderResource() = default;

	[[nodiscard]] FORCEINLINE ID3D12Resource* GetDxResource() const noexcept { return mDxResource.Get(); }

protected:

	Microsoft::WRL::ComPtr<ID3D12Resource> mDxResource;

	D3D12_RESOURCE_STATES mResourceState = D3D12_RESOURCE_STATE_COMMON;

	ResourceLocation mResourceLocation;
};

#pragma endregion

#pragma region Texture

struct TextureDesc
{
	[[nodiscard]] FORCEINLINE const D3D12_RESOURCE_DESC* GetResourceDesc() const noexcept { return &desc; }

	[[nodiscard]] FORCEINLINE const D3D12_CLEAR_VALUE* GetOptimizedClearValue() const noexcept { return &optimizedClearValue; }

	D3D12_RESOURCE_DESC desc;
	D3D12_CLEAR_VALUE optimizedClearValue;
};

class Texture : public RenderResource
{
public:

	Texture(Device& device, const TextureDesc& textureDesc);

	Texture(Microsoft::WRL::ComPtr<ID3D12Resource>&& dxResource);

public:

	static std::unique_ptr<Texture> CreateFromFile(std::wstring_view fileName, Device& device, CommandContext* context, bool createSRV = true);
	
	static std::unique_ptr<Texture> CreateFromFile(std::wstring_view fileName, Device& device, bool createSRV = true);

	void UpdateTextureData(CommandContext* context, std::span<D3D12_SUBRESOURCE_DATA> subresourceData);

public:

	void CreateShaderResourceView(Device& device, const D3D12_SHADER_RESOURCE_VIEW_DESC& desc);

	void CreateRenderTargetView(Device& device, const D3D12_RENDER_TARGET_VIEW_DESC& desc);

	void CreateDepthStencilView(Device& device, const D3D12_DEPTH_STENCIL_VIEW_DESC& desc);

public:

	[[nodiscard]] FORCEINLINE ShaderResourceView* GetShaderResourceView() const noexcept { return mShaderResourceView.get(); }

	[[nodiscard]] FORCEINLINE RenderTargetView* GetRenderTargetView() const noexcept { return mRenderTargetView.get(); }

	[[nodiscard]] FORCEINLINE DepthStencilView* GetDepthStencilView() const noexcept { return mDepthStencilView.get(); }

protected:

	std::unique_ptr<ShaderResourceView> mShaderResourceView;

	std::unique_ptr<RenderTargetView> mRenderTargetView;

	std::unique_ptr<DepthStencilView> mDepthStencilView;
};

#pragma endregion

#pragma region DefaultBuffer

class DefaultBuffer : public RenderResource
{
public:

	DefaultBuffer(Device& device, std::size_t byteSize);

public:

	template<typename T>
	void UploadBufferData(CommandContext* context, std::span<const T> data, D3D12_RESOURCE_STATES finalState)
	{
		UploadBufferData(context, data.data(), data.size_bytes(), finalState);
	}

protected:

	void UploadBufferData(CommandContext* context, const void* data, std::size_t dataByteSize, D3D12_RESOURCE_STATES finalState);
};

#pragma endregion

#pragma region VertexBuffer

class VertexBuffer : public DefaultBuffer
{
public:

	VertexBuffer(Device& device, std::size_t byteSize, uint32 byteStride);

public:

	template<typename T>
	void UploadBufferData(CommandContext* context, std::span<const T> data)
	{
		ensure(sizeof(T) == mByteStride);
		DefaultBuffer::UploadBufferData(context, data, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);
	}

	[[nodiscard]] D3D12_VERTEX_BUFFER_VIEW GetVertexBufferView() const noexcept;

protected:

	uint32 mByteStride;
};

#pragma endregion

#pragma region IndexBuffer

class IndexBuffer : public DefaultBuffer
{
public:

	IndexBuffer(Device& device, std::size_t byteSize, DXGI_FORMAT indexFormat);

public:

	template<typename T>
	void UploadBufferData(CommandContext* context, std::span<const T> data)
	{
		DefaultBuffer::UploadBufferData<T>(context, data, D3D12_RESOURCE_STATE_INDEX_BUFFER);
	}

	[[nodiscard]] D3D12_INDEX_BUFFER_VIEW GetIndexBufferView() const noexcept;

protected:

	DXGI_FORMAT mIndexFormat;
};

#pragma endregion

#pragma region ConstantBuffer

class ConstantBuffer : public RenderResource
{
public:

	ConstantBuffer(Device& device, uint32 elementCount, uint32 elementByteSize);

	~ConstantBuffer();

	ConstantBuffer(const ConstantBuffer&) = delete;

	ConstantBuffer& operator=(const ConstantBuffer&) = delete;

	ConstantBuffer(ConstantBuffer&&) = delete;

	ConstantBuffer& operator=(ConstantBuffer&&) = delete;

public:

	void UpdateBufferData(const void* data, std::size_t size);

	[[nodiscard]] const ConstantBufferView& GetConstantBufferView() const noexcept { return *mConstantBufferView; }

protected:

	uint64 mElementByteSize;

	std::unique_ptr<ConstantBufferView> mConstantBufferView;
};

#pragma endregion