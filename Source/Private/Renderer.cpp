#include "App.h"
#include "Chunk.h"
#include "Device.h"
#include "DxUtil.h"
#include "InputLayout.h"
#include "PipelineState.h"
#include "Renderer.h"
#include "RenderResource.h"
#include "ResourceManager.h"
#include "RootSignature.h"
#include "Types.h"
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3dx12.h>
#include <memory>
#include <utility>
#include <vector>

RenderData::~RenderData()
{
	if (mVertexBuffer)
	{
		App::Get().GetResourceManager().AddPendingDelete(std::move(mVertexBuffer), mFenceValue);
	}
	if (mIndexBuffer)
	{
		App::Get().GetResourceManager().AddPendingDelete(std::move(mIndexBuffer), mFenceValue);
	}
	if (mConstantBuffer)
	{
		App::Get().GetResourceManager().AddPendingDelete(std::move(mConstantBuffer), mFenceValue);
	}
}

void RenderData::SetVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer)
{
	if (mVertexBuffer)
	{
		App::Get().GetResourceManager().AddPendingDelete(std::move(mVertexBuffer), mFenceValue);
	}
	mVertexBuffer = std::move(vertexBuffer);
}

void RenderData::SetIndexBuffer(std::unique_ptr<IndexBuffer> indexBuffer)
{
	if (mIndexBuffer)
	{
		App::Get().GetResourceManager().AddPendingDelete(std::move(mIndexBuffer), mFenceValue);
	}
	mIndexBuffer = std::move(indexBuffer);
}

void RenderData::SetConstantBuffer(std::unique_ptr<ConstantBuffer> constantBuffer)
{
	if (mConstantBuffer)
	{
		App::Get().GetResourceManager().AddPendingDelete(std::move(mConstantBuffer), mFenceValue);
	}
	mConstantBuffer = std::move(constantBuffer);
}

void RenderData::SetFenceValue(uint64 fenceValue)
{
	mFenceValue = fenceValue;
}


ChunkRenderer::ChunkRenderer(Device& device)
{
	LoadAssets(device);

	RootSignatureInitializer rootSignatureInitializer;
	InitRootSignature(rootSignatureInitializer);

	mRootSignature = std::make_unique<RootSignature>(rootSignatureInitializer, device);


	PipelineStateInitializer PSOInitializer;
	InitPipelineState(PSOInitializer);

	mPipelineState = std::make_unique<PipelineState>(PSOInitializer, device);
}

void ChunkRenderer::Draw(FrameResource& frameResource, const std::vector<RenderData*>& chunksRenderData)
{
	auto& context = frameResource.commandContext;
	ID3D12GraphicsCommandList* dxCommandList = context->GetDxCommandList();

	dxCommandList->SetPipelineState(mPipelineState->GetDxPSO());
	dxCommandList->SetGraphicsRootSignature(mRootSignature->GetDxRootSignature());


	dxCommandList->SetGraphicsRootDescriptorTable(0, frameResource.passConstantsCB->GetConstantBufferView().GetGPUDescriptorHandle());
	dxCommandList->SetGraphicsRootDescriptorTable(1, mBlockTextureAtlas->GetShaderResourceView()->GetGPUDescriptorHandle());


	for (RenderData* renderData : chunksRenderData)
	{
		dxCommandList->SetGraphicsRootDescriptorTable(2, renderData->GetConstantBuffer()->GetConstantBufferView().GetGPUDescriptorHandle());

		D3D12_VERTEX_BUFFER_VIEW vertexBufferView = renderData->GetVertexBuffer()->GetVertexBufferView();
		D3D12_INDEX_BUFFER_VIEW indexBufferView = renderData->GetIndexBuffer()->GetIndexBufferView();

		dxCommandList->IASetVertexBuffers(0, 1, &vertexBufferView);
		dxCommandList->IASetIndexBuffer(&indexBufferView);
		dxCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		uint32 numIndices = indexBufferView.SizeInBytes / static_cast<uint32>(sizeof(uint32));
		dxCommandList->DrawIndexedInstanced(numIndices, 1, 0, 0, 0);

		renderData->SetFenceValue(frameResource.fenceValue); // This will need to be reworked if multi-threading command list submission.
	}

}

void ChunkRenderer::LoadAssets(Device& device)
{
	mBlockTextureAtlas = Texture::CreateFromFile(mBlockTextureAtlasFilePath, device);
}

void ChunkRenderer::InitRootSignature(RootSignatureInitializer& initializer)
{
	initializer.AddDescriptorTable({ CD3DX12_DESCRIPTOR_RANGE{ D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0 } }); // View matrix
	initializer.AddDescriptorTable({ CD3DX12_DESCRIPTOR_RANGE{ D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1, 0 } }); // Texture atlas
	initializer.AddDescriptorTable({ CD3DX12_DESCRIPTOR_RANGE{ D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 1 } }); // Chunk constants

	initializer.AddStaticSamplers({ StaticSamplers::PointClamp });
}

void ChunkRenderer::InitPipelineState(PipelineStateInitializer& initializer)
{
	ensure(mRootSignature);

	initializer.SetRootSignature(*mRootSignature);

	initializer.SetShaderInput(GetShaderInput());

	mVertexShader.CompileFromFile(sShaderFilePath, "VS", "vs_5_0");
	initializer.SetVertexShader(mVertexShader);

	mPixelShader.CompileFromFile(sShaderFilePath, "PS", "ps_5_0");
	initializer.SetPixelShader(mPixelShader);

	initializer.SetBlendState(BlendPresets::Alpha);
	initializer.SetRenderTargetFormats({ sBackBufferFormat });
	initializer.SetDepthStencilFormat(sDepthStencilFormat);
}

ShaderInput ChunkRenderer::GetShaderInput()
{
	ShaderInput shaderInput;

	shaderInput.AddVertexElement<Vector3D>("POSITION", 0, STRUCT_OFFSET(BlockVertex, position));
	shaderInput.AddVertexElement<Vector3D>("NORMAL", 0, STRUCT_OFFSET(BlockVertex, normal));
	shaderInput.AddVertexElement<uint16>("TEXINDEX", 0, STRUCT_OFFSET(BlockVertex, textureOffset));
	shaderInput.AddVertexElement<uint16>("TEXINDEX", 1, STRUCT_OFFSET(BlockVertex, overlayTextureOffset));
	shaderInput.AddVertexElement<Vector2D>("TEXCOORD", 0, STRUCT_OFFSET(BlockVertex, textureUV));
	shaderInput.AddVertexElement<Color>("COLOR", 0, STRUCT_OFFSET(BlockVertex, textureTint));
	shaderInput.AddVertexElement<Color>("COLOR", 1, STRUCT_OFFSET(BlockVertex, overlayTextureTint));

	return shaderInput;
}





