#pragma once

#include "Core.h"
#include "Types.h"
#include <d3d12.h>
#include <d3dx12.h>
#include <span>
#include <vector>
#include <wrl/client.h>

class Device;

struct RootSignatureInitializer
{
	friend class RootSignature;

public:

	void AddDescriptorTable(const std::vector<CD3DX12_DESCRIPTOR_RANGE>& descriptorTable, D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL);

	void AddShaderResourceView(uint32 shaderRegister, uint32 registerSpace = 0, D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL);

	void AddConstantBufferView(uint32 shaderRegister, uint32 registerSpace = 0, D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL);

	void AddUnorderedAccessView(uint32 shaderRegister, uint32 registerSpace = 0, D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL);

	void Add32BitConstants(uint32 numValues, uint32 shaderRegister, uint32 registerSpace = 0, D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL);

	void AddStaticSamplers(const std::vector<D3D12_STATIC_SAMPLER_DESC>& staticSamplerDescs);

private:

	std::vector<D3D12_STATIC_SAMPLER_DESC> staticSamplers;

	std::vector<CD3DX12_ROOT_PARAMETER> rootParameters;

	std::vector<std::vector<CD3DX12_DESCRIPTOR_RANGE>> descriptorTables; // The pointers to descriptor ranges need to persist until the root signature is serialized so make a copy
};


class RootSignature
{
public:

	RootSignature(const RootSignatureInitializer& initializer, Device& device);

public:

	[[nodiscard]] FORCEINLINE ID3D12RootSignature* GetDxRootSignature() const noexcept { return mDxRootSignature.Get(); }

protected:

	Microsoft::WRL::ComPtr<ID3D12RootSignature> mDxRootSignature;
};
