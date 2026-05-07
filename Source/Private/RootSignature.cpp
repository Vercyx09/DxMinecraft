#include "Device.h"
#include "DxUtil.h"
#include "RootSignature.h"
#include "Types.h"
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3dx12.h>
#include <span>
#include <vector>
#include <Windows.h>
#include <wrl/client.h>
#include "App.h"

using namespace Microsoft::WRL;

void RootSignatureInitializer::AddDescriptorTable(const std::vector<CD3DX12_DESCRIPTOR_RANGE>& descriptorTable, D3D12_SHADER_VISIBILITY visibility)
{
	descriptorTables.emplace_back(descriptorTable.begin(), descriptorTable.end());

	CD3DX12_ROOT_PARAMETER rootParameter;
	rootParameter.InitAsDescriptorTable(static_cast<uint32>(descriptorTable.size()), descriptorTables.back().data(), visibility);

	rootParameters.push_back(rootParameter);
}

void RootSignatureInitializer::AddShaderResourceView(uint32 shaderRegister, uint32 registerSpace, D3D12_SHADER_VISIBILITY visibility)
{
	CD3DX12_ROOT_PARAMETER rootParameter;
	rootParameter.InitAsShaderResourceView(shaderRegister, registerSpace, visibility);

	rootParameters.push_back(rootParameter);
}

void RootSignatureInitializer::AddConstantBufferView(uint32 shaderRegister, uint32 registerSpace, D3D12_SHADER_VISIBILITY visibility)
{
	CD3DX12_ROOT_PARAMETER rootParameter;
	rootParameter.InitAsConstantBufferView(shaderRegister, registerSpace, visibility);

	rootParameters.push_back(rootParameter);
}

void RootSignatureInitializer::AddUnorderedAccessView(uint32 shaderRegister, uint32 registerSpace, D3D12_SHADER_VISIBILITY visibility)
{
	CD3DX12_ROOT_PARAMETER rootParameter;
	rootParameter.InitAsUnorderedAccessView(shaderRegister, registerSpace, visibility);

	rootParameters.push_back(rootParameter);
}

void RootSignatureInitializer::Add32BitConstants(uint32 numValues, uint32 shaderRegister, uint32 registerSpace, D3D12_SHADER_VISIBILITY visibility)
{
	CD3DX12_ROOT_PARAMETER rootParameter;
	rootParameter.InitAsConstants(numValues, shaderRegister, registerSpace, visibility);

	rootParameters.push_back(rootParameter);
}

void RootSignatureInitializer::AddStaticSamplers(const std::vector<D3D12_STATIC_SAMPLER_DESC>& staticSamplerDescs)
{
	staticSamplers.append_range(staticSamplerDescs);
}

RootSignature::RootSignature(const RootSignatureInitializer& initializer, Device& device)
{
	CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc{
		static_cast<uint32>(initializer.rootParameters.size()),
		initializer.rootParameters.data(),
		static_cast<uint32>(initializer.staticSamplers.size()),
		initializer.staticSamplers.data(),
		D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT
	};

	ComPtr<ID3DBlob> serializedBlob;
	ComPtr<ID3DBlob> errorBlob;
	HRESULT hr = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &serializedBlob, &errorBlob);

	if (errorBlob != nullptr)
	{
		OutputDebugStringA(static_cast<char*>(errorBlob->GetBufferPointer()));
	}
	DxCall(hr);

	DxCall(device.GetDxDevice()->CreateRootSignature(
		0,
		serializedBlob->GetBufferPointer(),
		serializedBlob->GetBufferSize(),
		IID_PPV_ARGS(&mDxRootSignature)
	));
}
