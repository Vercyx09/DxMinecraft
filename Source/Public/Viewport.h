#pragma once
#include "App.h"
#include "RenderResource.h"
#include "Types.h"
#include <array>
#include <d3d12.h>
#include <dxgi1_2.h>
#include <dxgiformat.h>
#include <memory>
#include <Windows.h>
#include <wrl/client.h>

class Adapter;
class Device;

class Viewport
{

public:

	Viewport(const Adapter& adapter, HWND windowHandle, uint16 width, uint16 height, DXGI_FORMAT pixelFormat, bool allowTearing = false);

public:

	void Present();

	void OnResize(uint16 newWidth, uint16 newHeight);

protected:

	void CreateDepthStencilBuffer();

#pragma region Getters

public:

	[[nodiscard]] FORCEINLINE uint8 GetCurrentBackBufferIndex() const noexcept { return mCurrentBackBufferIndex; }

	[[nodiscard]] FORCEINLINE ID3D12Resource* GetCurrentBackBufferResource() const noexcept
	{
		return mBackBuffers[mCurrentBackBufferIndex]->GetDxResource();
	}

	[[nodiscard]] D3D12_CPU_DESCRIPTOR_HANDLE GetCurrentBackBufferView() const;

	[[nodiscard]] FORCEINLINE ID3D12Resource* GetDepthStencilBufferResource() const noexcept
	{
		return mDepthStencilBuffer->GetDxResource();
	}

	[[nodiscard]] D3D12_CPU_DESCRIPTOR_HANDLE GetDepthStencilView() const { return mDepthStencilBuffer->GetDepthStencilView()->GetCPUDescriptorHandle(); }

	[[nodiscard]] FORCEINLINE D3D12_VIEWPORT GetDxViewport() const noexcept { return mDxViewport; }

	[[nodiscard]] FORCEINLINE D3D12_RECT GetDxScissorRect() const noexcept { return mDxScissorRect; }

#pragma endregion

protected:

	uint16 mWidth;
	uint16 mHeight;
	DXGI_FORMAT mPixelFormat;
	uint32 mSwapChainFlags;
	uint8 mCurrentBackBufferIndex;

	bool mAllowTearing;

	Device& mParentDevice;

	D3D12_VIEWPORT mDxViewport = { 0 };

	D3D12_RECT mDxScissorRect = { 0 };

protected:

	Microsoft::WRL::ComPtr<IDXGISwapChain1> mDxSwapChain;

	std::array<std::unique_ptr<Texture>, App::NumSwapChainBuffers> mBackBuffers;
	std::unique_ptr<Texture> mDepthStencilBuffer;
};