#include "CommandContext.h"
#include "Device.h"
#include "DLog.h"
#include "DxUtil.h"
#include "Types.h"
#include <d3d12.h>
#include <format>
#include <Windows.h>


static constexpr uint64 UPLOAD_ALLOCATOR_SIZE = 256 * 1024 * 1024; // 256 MB

CommandContext::CommandContext(Device& device)
	:
	mParentDevice(device),
	mUploadAllocator(device, UPLOAD_ALLOCATOR_SIZE)
{
	ID3D12Device* dxDevice = mParentDevice.GetDxDevice();

	DxCall(dxDevice->CreateCommandAllocator(
		D3D12_COMMAND_LIST_TYPE_DIRECT,
		IID_PPV_ARGS(&mDxCommandAllocator)
	));

	DxCall(dxDevice->CreateCommandList(
		0,
		D3D12_COMMAND_LIST_TYPE_DIRECT,
		mDxCommandAllocator.Get(),
		nullptr,
		IID_PPV_ARGS(&mDxCommandList)));

	DxCall(mDxCommandList->Close());
	DxCall(mDxCommandList->Reset(mDxCommandAllocator.Get(), nullptr));
}

CommandContext::~CommandContext()
{
	DLog::Log("Destroying a command context");
}

void CommandContext::Reset(ID3D12PipelineState* pso)
{
	mResourceStateMap.clear();

	// TODO: ??
	while (!mPendingResourceBarriers.empty())
	{
		mPendingResourceBarriers.pop();
	}

	if (!mIsClosed)
	{
		Close();
	}

	DxCall(mDxCommandAllocator->Reset());
	DxCall(mDxCommandList->Reset(mDxCommandAllocator.Get(), pso));

	mUploadAllocator.Reset();

	mIsClosed = false;
}

void CommandContext::Close()
{
	ensure(!mIsClosed);

	DxCall(mDxCommandList->Close());
	mIsClosed = true;
}
