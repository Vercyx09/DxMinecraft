#define NOMINMAX

#include "Device.h"
#include "DxUtil.h"
#include "InputLayout.h"
#include "PipelineState.h"
#include "RootSignature.h"
#include "Shader.h"
#include "Types.h"
#include <cstddef>
#include <cstring>
#include <d3d12.h>
#include <d3dx12.h>
#include <dxgiformat.h>
#include <limits>
#include <span>
#include <Windows.h>


PipelineStateInitializer::PipelineStateInitializer()
{
	std::memset(&pipelineStateDesc, 0, sizeof(pipelineStateDesc));

	pipelineStateDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
	pipelineStateDesc.SampleMask = std::numeric_limits<uint32>::max();
	pipelineStateDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
	pipelineStateDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
	pipelineStateDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	pipelineStateDesc.SampleDesc = {
		.Count = 1,
		.Quality = 0
	};
}

void PipelineStateInitializer::SetRootSignature(RootSignature& rootSignature)
{
	pipelineStateDesc.pRootSignature = rootSignature.GetDxRootSignature();
}

void PipelineStateInitializer::SetVertexShader(VertexShader& vertexShader)
{
	std::span<const std::byte> byteCode = vertexShader.GetByteCode();

	pipelineStateDesc.VS = {
		.pShaderBytecode = byteCode.data(),
		.BytecodeLength = byteCode.size()
	};
}

void PipelineStateInitializer::SetPixelShader(PixelShader& pixelShader)
{
	std::span<const std::byte> byteCode = pixelShader.GetByteCode();

	pipelineStateDesc.PS = {
		.pShaderBytecode = byteCode.data(),
		.BytecodeLength = byteCode.size()
	};
}

void PipelineStateInitializer::SetShaderInput(const ShaderInput& shaderInput_)
{
	shaderInput = shaderInput_;

	pipelineStateDesc.InputLayout = {
		.pInputElementDescs = shaderInput.inputElements.data(),
		.NumElements = static_cast<uint32>(shaderInput.inputElements.size())
	};
}

void PipelineStateInitializer::SetRenderTargetFormats(const std::vector<DXGI_FORMAT>& formats)
{
	ensure(formats.size() <= 8);

	pipelineStateDesc.NumRenderTargets = static_cast<uint32>(formats.size());

	for (std::size_t i = 0; i < formats.size() && i < 8; i++)
	{
		pipelineStateDesc.RTVFormats[i] = formats[i];
	}
}

void PipelineStateInitializer::SetDepthStencilFormat(DXGI_FORMAT format)
{
	pipelineStateDesc.DSVFormat = format;
}

void PipelineStateInitializer::SetBlendState(D3D12_RENDER_TARGET_BLEND_DESC blendDesc)
{
	pipelineStateDesc.BlendState.IndependentBlendEnable = FALSE;
	pipelineStateDesc.BlendState.RenderTarget[0] = blendDesc;
}

void PipelineStateInitializer::SetBlendStates(const std::vector<D3D12_RENDER_TARGET_BLEND_DESC>& blendDescs)
{
	ensure(blendDescs.size() <= 8);

	pipelineStateDesc.BlendState.IndependentBlendEnable = TRUE;
	for (std::size_t i = 0; i < blendDescs.size() && i < 8; i++)
	{
		pipelineStateDesc.BlendState.RenderTarget[i] = blendDescs[i];
	}

}

void PipelineStateInitializer::SetAlphaToCoverage(bool enabled)
{
	pipelineStateDesc.BlendState.AlphaToCoverageEnable = enabled;
}


PipelineState::PipelineState(const PipelineStateInitializer& initializer, Device& device)
{
	DxCall(device.GetDxDevice()->CreateGraphicsPipelineState(
		&initializer.pipelineStateDesc,
		IID_PPV_ARGS(&mDxPSO))
	);
}
