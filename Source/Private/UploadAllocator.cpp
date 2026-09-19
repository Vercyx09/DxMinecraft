#include "Device.h"
#include "DLog.h"
#include "DxUtil.h"
#include "Types.h"
#include "UploadAllocator.h"
#include <d3d12.h>
#include <d3dx12.h>
#include <Windows.h>

UploadAllocator::UploadAllocator(Device& device, uint64 size)
	:
	mSize(size)
{
	CD3DX12_HEAP_PROPERTIES heapProperties(D3D12_HEAP_TYPE_UPLOAD);
	CD3DX12_RESOURCE_DESC resourceDesc = CD3DX12_RESOURCE_DESC::Buffer(size);

	DxCall(device.GetDxDevice()->CreateCommittedResource(
		&heapProperties,
		D3D12_HEAP_FLAG_NONE,
		&resourceDesc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&mDxResource)
	));

	mDxResource->Map(0, nullptr, reinterpret_cast<void**>(&mCPUBase));
	mGPUBase = mDxResource->GetGPUVirtualAddress();
}

ResourceLocation UploadAllocator::Allocate(uint64 size, uint64 alignment)
{
	ensure(alignment != 0 && (alignment & (alignment - 1)) == 0); // alignment must be a power of 2
	
	uint64 alignedOffset = DxUtil::AlignTo(mOffset, alignment);
	
	//ensure(alignedOffset + size < mSize);
	if (alignedOffset + size > mSize)
	{
		ensure(false);
		DLog::Error("UploadAllocator: Out of memory! "
			"Requested size: {}, alignment: {}, allocator size: {}",
			size, alignment, mSize
		);
		return ResourceLocation{};
	}

	mOffset = alignedOffset + size;

	return ResourceLocation{
		.CPU = mCPUBase + alignedOffset,
		.GPU = mGPUBase + alignedOffset,
		.Resource = mDxResource.Get(),
		.Offset = alignedOffset,
		.Size = size
	};
}

void UploadAllocator::Reset()
{
#ifdef DEBUG
	//memset(mCPUBase, 0xCD, mSize);
#endif
	mOffset = 0;
}
