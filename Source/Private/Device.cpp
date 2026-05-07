#include "App.h"
#include "DescriptorHeap.h"
#include "Device.h"
#include "DxUtil.h"
#include "QueryHeap.h"
#include "Types.h"
#include <CommandContext.h>
#include <cstdlib>
#include <d3d12.h>
#include <DLog.h>
#include <memory>
#include <mutex>
#include <utility>
#include <Windows.h>
#include <wrl/client.h>


Device::Device(Microsoft::WRL::ComPtr<ID3D12Device>&& dxDevice)
	:
	mDxDevice(std::move(dxDevice))
{
	mDxDevice->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&mDxFence));

	D3D12_COMMAND_QUEUE_DESC commandQueueDesc{
		.Type = D3D12_COMMAND_LIST_TYPE_DIRECT,
		.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL,
		.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE,
		.NodeMask = 0
	};
	DxCall(mDxDevice->CreateCommandQueue(&commandQueueDesc, IID_PPV_ARGS(&mDxDirectQueue)));

	CreateDescriptorHeaps();
	CreateQueryHeaps();

	mDirectContext = ObtainCommandContext();

	DxCall(mDxDirectQueue->GetTimestampFrequency(&mDirectQueueFrequency));
}

Device::~Device() = default;

void Device::CreateDescriptorHeaps()
{
	mDescriptorHeapManager = std::make_unique<DescriptorHeapManager>(*this);

	mDescriptorHeapManager->AllocateDescriptorHeap(EDescriptorHeapType::RenderTarget, App::NumSwapChainBuffers);
	mDescriptorHeapManager->AllocateDescriptorHeap(EDescriptorHeapType::DepthStencil, 1);
	mDescriptorHeapManager->AllocateDescriptorHeap(EDescriptorHeapType::GeneralGPUVisible, 4096);
}

void Device::CreateQueryHeaps()
{
	mTimestampHeap = std::make_unique<TimestampQueryHeap>(*this, 6);
}


std::unique_ptr<CommandContext> Device::ObtainCommandContext()
{
	std::scoped_lock lock(mContextPoolMutex);

	if (!mContextPool.empty())
	{
		std::unique_ptr<CommandContext> context = std::move(mContextPool.back());
		mContextPool.pop_back();
		return context;
	}

	DLog::Log("Creating a new command context");
	return std::make_unique<CommandContext>(*this);
}

void Device::SubmitCommandContext(std::unique_ptr<CommandContext>& context)
{
	ensure(context);

	context->Close();

	ID3D12GraphicsCommandList* cmdList = context->GetDxCommandList();

	ID3D12CommandList* cmdsLists[] = { cmdList };
	mDxDirectQueue->ExecuteCommandLists(_countof(cmdsLists), cmdsLists);
	
	//FlushCommandQueue();

	//ReleaseCommandContext(std::move(context));
}

void Device::ReleaseCommandContext(std::unique_ptr<CommandContext>&& context)
{
	context->Reset();

	{
		std::scoped_lock lock(mContextPoolMutex);
		mContextPool.push_back(std::move(context));
	}
}



float Device::GetFrameTime(uint64 index)
{
	auto data = mTimestampHeap->GetQueryData(index, 2);
	return (static_cast<float>(data[1] - data[0]) / static_cast<float>(mDirectQueueFrequency)) * 1000.0f;
}

ID3D12QueryHeap* Device::GetDxQueryHeap()
{
	return mTimestampHeap->GetDxQueryHeap();
}

ID3D12Resource* Device::GetDxQueryBuffer()
{
	return mTimestampHeap->GetDxReadbackBufferResource();
}


void Device::FlushCommandQueue()
{
	// Increment the CPU value
	mCurrentFenceValue++;

	// Tell the GPU to update it to the new value
	DxCall(mDxDirectQueue->Signal(mDxFence.Get(), mCurrentFenceValue));

	// Wait untill the value is updated on the GPU
	if (mDxFence->GetCompletedValue() < mCurrentFenceValue)
	{
		HANDLE eventHandle = CreateEventEx(NULL, NULL, 0, EVENT_ALL_ACCESS);
		ensure(eventHandle);

		DxCall(mDxFence->SetEventOnCompletion(mCurrentFenceValue, eventHandle));

		WaitForSingleObject(eventHandle, INFINITE);
		CloseHandle(eventHandle);
	}
}

void Device::SetFenceEvent(uint64 fenceValue, HANDLE eventHandle)
{
	mDxFence->SetEventOnCompletion(fenceValue, eventHandle);
	//ensure(mCurrentFenceValue < fenceValue);
/*	if (mCurrentFenceValue < fenceValue)
	{
		mDxFence->SetEventOnCompletion(fenceValue, eventHandle);
	}*/
}

void Device::SignalFence()
{
	mCurrentFenceValue++;
	mDxDirectQueue->Signal(mDxFence.Get(), mCurrentFenceValue);
}
