#pragma once
#include "CommandContext.h"
#include "Core.h"
#include "InputLayout.h"
#include "PipelineState.h"
#include "RenderResource.h"
#include "RootSignature.h"
#include "Shader.h"
#include "Types.h"
#include <dxgiformat.h>
#include <memory>
#include <string_view>
#include <vector>


struct FrameResource
{
	std::unique_ptr<CommandContext> commandContext;
	std::unique_ptr<ConstantBuffer> passConstantsCB;
	uint64 fenceValue = 0;
};

class RenderData
{
public:

	~RenderData();

public:

	[[nodiscard]] FORCEINLINE VertexBuffer* GetVertexBuffer() noexcept { return mVertexBuffer.get(); }

	[[nodiscard]] FORCEINLINE IndexBuffer* GetIndexBuffer() noexcept { return mIndexBuffer.get(); }

	[[nodiscard]] FORCEINLINE ConstantBuffer* GetConstantBuffer() noexcept { return mConstantBuffer.get(); }

	[[nodiscard]] FORCEINLINE uint64 GetFenceValue() const noexcept { return mFenceValue; }

public:

	void SetVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer);

	void SetIndexBuffer(std::unique_ptr<IndexBuffer> indexBuffer);

	void SetConstantBuffer(std::unique_ptr<ConstantBuffer> constantBuffer);

	void SetFenceValue(uint64 fenceValue);

protected:

	std::unique_ptr<VertexBuffer> mVertexBuffer;
	std::unique_ptr<IndexBuffer> mIndexBuffer;
	std::unique_ptr<ConstantBuffer> mConstantBuffer;
	uint64 mFenceValue = 0;
};

class RootSignature;
class Device;



class ChunkRenderer
{
public:

	ChunkRenderer(Device& device);

public:

	void Draw(FrameResource& frameResource, const std::vector<RenderData*>& chunksRenderData);

protected:

	void LoadAssets(Device& device);

	void InitRootSignature(RootSignatureInitializer& initializer);

	void InitPipelineState(PipelineStateInitializer& initializer);

	[[nodiscard]] static ShaderInput GetShaderInput();

protected:

	std::unique_ptr<RootSignature> mRootSignature;

	std::unique_ptr<PipelineState> mPipelineState;

	VertexShader mVertexShader;

	PixelShader mPixelShader;

	std::unique_ptr<Texture> mBlockTextureAtlas;

protected:

	static constexpr std::wstring_view sShaderFilePath = L"../../Assets/Shaders/chunk.hlsl";
	static constexpr std::wstring_view mBlockTextureAtlasFilePath = L"../../Assets/Textures/Blocks/Output/blocks.dds";
	static constexpr DXGI_FORMAT sBackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
	static constexpr DXGI_FORMAT sDepthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
};