#pragma once
#include "DxUtil.h"
#include "Types.h"
#include <d3d12.h>
#include <dxgiformat.h>
#include <string_view>
#include <utility>
#include <vector>

template<typename T>
concept HasDefinedDxgiFormat = requires { DxgiFormat<T>::value; };

struct ShaderInput
{
	template<typename T>
	void AddVertexElement(std::string_view semanticName, uint32 semanticIndex, uint32 alignedByteOffset, uint32 inputSlot = 0)
		requires HasDefinedDxgiFormat<T>
	{
		AddVertexElement(semanticName, semanticIndex, DxgiFormat<T>::value, alignedByteOffset, inputSlot);
	}

	void AddVertexElement(std::string_view semanticName, uint32 semanticIndex, DXGI_FORMAT format, uint32 alignedByteOffset, uint32 inputSlot = 0)
	{
		AddElement(semanticName, semanticIndex, format, alignedByteOffset, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, inputSlot, 0);
	}

	template<typename T>
	void AddInstanceElement(std::string_view semanticName, uint32 semanticIndex, uint32 alignedByteOffset, uint32 inputSlot = 0, uint32 stepRate = 0)
		requires HasDefinedDxgiFormat<T>
	{
		AddInstanceElement(semanticName, semanticIndex, DxgiFormat<T>::value, alignedByteOffset, stepRate, inputSlot);
	}

	void AddInstanceElement(std::string_view semanticName, uint32 semanticIndex, DXGI_FORMAT format, uint32 alignedByteOffset, uint32 inputSlot = 0, uint32 stepRate = 1)
	{
		AddElement(semanticName, semanticIndex, format, alignedByteOffset, D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA, inputSlot, stepRate);
	}

	void AddElement(std::string_view semanticName, uint32 semanticIndex, DXGI_FORMAT format, uint32 alignedByteOffset, D3D12_INPUT_CLASSIFICATION inputSlotClass, uint32 inputSlot, uint32 stepRate)
	{
		D3D12_INPUT_ELEMENT_DESC element{
			.SemanticName = semanticName.data(),
			.SemanticIndex = semanticIndex,
			.Format = format,
			.InputSlot = inputSlot,
			.AlignedByteOffset = alignedByteOffset,
			.InputSlotClass = inputSlotClass,
			.InstanceDataStepRate = stepRate
		};

		inputElements.push_back(std::move(element));
	}

	std::vector<D3D12_INPUT_ELEMENT_DESC> inputElements;
};
