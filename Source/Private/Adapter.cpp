#include "Adapter.h"
#include "Device.h"
#include "DLog.h"
#include "DxUtil.h"
#include "Types.h"
#include <d3d12.h>
#include <d3d12sdklayers.h>
#include <d3dcommon.h>
#include <dxgi1_3.h>
#include <dxgi1_6.h>
#include <format>
#include <memory>
#include <utility>
#include <Windows.h>
#include <wrl/client.h>

using namespace Microsoft::WRL;

static EGPUVendor GetGPUVendorFromID(uint32 vendorID)
{
	switch (vendorID)
	{
	case 0x10DE:
		return EGPUVendor::NVIDIA;
	case 0x1002:
	case 0x1022:
		return EGPUVendor::AMD;
	case 0x8086:
		return EGPUVendor::Intel;
	case 0x1414:
		return EGPUVendor::Microsoft;
	}

	return EGPUVendor::Unknown;
}


Adapter::Adapter()
{
	uint32 dxgiFactoryFlags = 0;

#ifdef DEBUG
	dxgiFactoryFlags = DXGI_CREATE_FACTORY_DEBUG;
#endif

	DxCall(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&mDxFactory)));

	ComPtr<ID3D12Device> dxDevice;
	DXGI_ADAPTER_DESC3 adapterDesc = {};

	for (uint32 i = 0; SUCCEEDED(mDxFactory->EnumAdapterByGpuPreference(i, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&mDxAdapter))); i++)
	{
		ensure(SUCCEEDED(mDxAdapter->GetDesc3(&adapterDesc)));

		if (adapterDesc.Flags & DXGI_ADAPTER_FLAG3_SOFTWARE)
		{
			continue; // Skip software adapters for now
		}

		if (SUCCEEDED(D3D12CreateDevice(mDxAdapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&dxDevice))))
		{
			break;
		}
	}

	if (!dxDevice)
	{
		DLog::Log("Failed to find a suitable hardware adapter! Falling back to a software adapter.");

		mDxFactory->EnumWarpAdapter(IID_PPV_ARGS(&mDxAdapter));
		DxCall(D3D12CreateDevice(mDxAdapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&dxDevice)));

		ensure(SUCCEEDED(mDxAdapter->GetDesc3(&adapterDesc)));
	}

#ifdef DEBUG
	{
		ComPtr<ID3D12InfoQueue> dxInfoQueue;
		DxCall(dxDevice.As(&dxInfoQueue));

		dxInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, TRUE);
		dxInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, TRUE);
		dxInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_WARNING, TRUE);
	}
#endif

	mDevice = std::make_unique<Device>(std::move(dxDevice));


	mAdapterInfo.deviceName = DxUtil::GetStringFromWCHAR(adapterDesc.Description);
	mAdapterInfo.dedicatedVideoMemory = adapterDesc.DedicatedVideoMemory;
	mAdapterInfo.dedicatedSystemMemory = adapterDesc.DedicatedSystemMemory;
	mAdapterInfo.sharedSystemMemory = adapterDesc.SharedSystemMemory;
	mAdapterInfo.vendor = GetGPUVendorFromID(adapterDesc.VendorId);
}
