#pragma once

#include "Core.h"
#include "Device.h"
#include "Types.h"
#include <dxgi1_6.h>
#include <memory>
#include <string>
#include <wrl/client.h>

enum class EGPUVendor
{
	Unknown,
	NVIDIA,
	AMD,
	Intel,
	Microsoft
};

struct AdapterInfo
{
	std::string deviceName;
	uint64 dedicatedVideoMemory = 0;
	uint64 dedicatedSystemMemory = 0;
	uint64 sharedSystemMemory = 0;
	EGPUVendor vendor = EGPUVendor::Unknown;

	[[nodiscard]] FORCEINLINE uint64 GetDedicatedVideoMemoryMB() const noexcept
	{
		return dedicatedVideoMemory / (1024ull * 1024ull);
	}

	[[nodiscard]] FORCEINLINE uint64 GetDedicatedSystemMemoryMB() const noexcept
	{
		return dedicatedSystemMemory / (1024ull * 1024ull);
	}

	[[nodiscard]] FORCEINLINE uint64 GetSharedSystemMemoryMB() const noexcept
	{
		return sharedSystemMemory / (1024ull * 1024ull);
	}
};

class Adapter
{
public:

	Adapter();

public:

	[[nodiscard]] FORCEINLINE IDXGIAdapter4* GetDxAdapter() const noexcept { return mDxAdapter.Get(); }

	[[nodiscard]] FORCEINLINE Device& GetDevice() const noexcept { return *mDevice; }
	
	[[nodiscard]] FORCEINLINE IDXGIFactory6* GetDxFactory() const noexcept { return mDxFactory.Get(); }

	[[nodiscard]] FORCEINLINE const AdapterInfo& GetAdapterInfo() const noexcept { return mAdapterInfo; }

protected:

	std::unique_ptr<Device> mDevice;

	Microsoft::WRL::ComPtr<IDXGIAdapter4> mDxAdapter;

	Microsoft::WRL::ComPtr<IDXGIFactory6> mDxFactory;


protected:

	AdapterInfo mAdapterInfo;
};