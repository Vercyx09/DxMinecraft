#pragma once
#include "Types.h"
#include <cstddef>
#include <d3d12.h>
#include <wrl/client.h>	


class Device;

struct ResourceLocation
{
	void* CPU = nullptr;
	D3D12_GPU_VIRTUAL_ADDRESS GPU = 0;
	ID3D12Resource* Resource = nullptr;
	uint64 Offset = 0;
	uint64 Size = 0;
};

class UploadAllocator
{
public:
	
	UploadAllocator(Device& device, uint64 size);

public:

	ResourceLocation Allocate(uint64 size, uint64 alignment);

	void Reset();

protected:

	Microsoft::WRL::ComPtr<ID3D12Resource> mDxResource;

	std::byte* mCPUBase = nullptr;
	D3D12_GPU_VIRTUAL_ADDRESS mGPUBase = 0;

	uint64 mSize;
	uint64 mOffset = 0;
};