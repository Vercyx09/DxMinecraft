#pragma once
#include "Core.h"
#include "InputLayout.h"
#include "Shader.h"
#include <d3d12.h>
#include <dxgiformat.h>
#include <span>
#include <wrl/client.h>

class Device;
class RootSignature;


struct PipelineStateInitializer
{
	friend class PipelineState;

public:

	PipelineStateInitializer();

public:

	void SetRootSignature(RootSignature& rootSignature);

	void SetVertexShader(VertexShader& vertexShader);

	void SetPixelShader(PixelShader& pixelShader);

	void SetShaderInput(const ShaderInput& shaderInput);
	
	void SetRenderTargetFormats(const std::vector<DXGI_FORMAT>& formats);

	void SetDepthStencilFormat(DXGI_FORMAT format);

	void SetBlendState(D3D12_RENDER_TARGET_BLEND_DESC blendDesc);

	void SetBlendStates(const std::vector<D3D12_RENDER_TARGET_BLEND_DESC>& blendDescs);

	void SetAlphaToCoverage(bool enabled);

private:

	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineStateDesc;

	ShaderInput shaderInput;
};


class PipelineState
{
public:

	PipelineState(const PipelineStateInitializer& initializer, Device& device);

public:

	[[nodiscard]] FORCEINLINE ID3D12PipelineState* GetDxPSO() const noexcept { return mDxPSO.Get(); }

protected:

	Microsoft::WRL::ComPtr<ID3D12PipelineState> mDxPSO;
};
