#include "DescriptorHeap.h"
#include "DxUtil.h"
#include "Viewport.h"
#include <Adapter.h>
#include <App.h>
#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgiformat.h>
#include <dxgitype.h>
#include <memory>
#include <RenderResource.h>
#include <Types.h>
#include <utility>
#include <Windows.h>
#include <wrl/client.h>

using namespace Microsoft::WRL;

Viewport::Viewport(const Adapter& adapter, HWND windowHandle, uint16 width, uint16 height, DXGI_FORMAT pixelFormat, bool allowTearing)
	:
	mWidth(width),
	mHeight(height),
	mPixelFormat(pixelFormat),
	mAllowTearing(allowTearing),
	mCurrentBackBufferIndex(0),
	mSwapChainFlags(DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH),
	mParentDevice(adapter.GetDevice())
{
	if (mAllowTearing)
	{
		mSwapChainFlags |= DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING;
	}

	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{
		.Width = width,
		.Height = height,
		.Format = pixelFormat,
		.Stereo = FALSE,
		.SampleDesc{
			.Count = 1,
			.Quality = 0
		},
		.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT,
		.BufferCount = App::NumSwapChainBuffers,
		.Scaling = DXGI_SCALING_NONE,
		.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD,
		.AlphaMode = DXGI_ALPHA_MODE_IGNORE,
		.Flags = mSwapChainFlags
	};

	DXGI_SWAP_CHAIN_FULLSCREEN_DESC swapChainFSDesc{
		.RefreshRate{
			.Numerator = 0,
			.Denominator = 0
		},
		.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED,
		.Scaling = DXGI_MODE_SCALING_UNSPECIFIED,
		.Windowed = TRUE
	};

	DxCall(adapter.GetDxFactory()->CreateSwapChainForHwnd(
		mParentDevice.GetDxDirectQueue(),
		windowHandle,
		&swapChainDesc,
		&swapChainFSDesc,
		nullptr,
		&mDxSwapChain
	));

	for (uint32 i = 0; i < App::NumSwapChainBuffers; i++)
	{
		ComPtr<ID3D12Resource> backBuffer;
		DxCall(mDxSwapChain->GetBuffer(i, IID_PPV_ARGS(&backBuffer)));

		mBackBuffers[i] = std::make_unique<Texture>(std::move(backBuffer));
	}

	// Make sure that DXGI does not change the window (e.g. enter full-screen mode when the ALT+ENTER is pressed)
	DxCall(adapter.GetDxFactory()->MakeWindowAssociation(windowHandle, DXGI_MWA_NO_WINDOW_CHANGES));
}

void Viewport::Present()
{
	DxCall(mDxSwapChain->Present(0, mAllowTearing ? DXGI_PRESENT_ALLOW_TEARING : 0));
	mCurrentBackBufferIndex = (mCurrentBackBufferIndex + 1) % App::NumSwapChainBuffers;
}

void Viewport::OnResize(uint16 newWidth, uint16 newHeight)
{
	mWidth = newWidth;
	mHeight = newHeight;

	for (auto& buffer : mBackBuffers)
	{
		buffer.reset();
	}

	DxCall(mDxSwapChain->ResizeBuffers(
		static_cast<uint32>(App::NumSwapChainBuffers),
		static_cast<uint32>(newWidth),
		static_cast<uint32>(newHeight),
		mPixelFormat,
		mSwapChainFlags
	));


	for (uint32 i = 0; i < App::NumSwapChainBuffers; i++)
	{
		ComPtr<ID3D12Resource> backBuffer;
		DxCall(mDxSwapChain->GetBuffer(i, IID_PPV_ARGS(&backBuffer)));

		D3D12_RENDER_TARGET_VIEW_DESC RTVDesc{
			.Format = mPixelFormat,
			.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D,
			.Texture2D {
				.MipSlice = 0,
				.PlaneSlice = 0
			}
		};

		mBackBuffers[i] = std::make_unique<Texture>(std::move(backBuffer));
		mBackBuffers[i]->CreateRenderTargetView(mParentDevice, RTVDesc);
	}
	CreateDepthStencilBuffer();

	mCurrentBackBufferIndex = 0;

	mDxViewport = {
		.TopLeftX = 0.0f,
		.TopLeftY = 0.0f,
		.Width = static_cast<float>(mWidth),
		.Height = static_cast<float>(mHeight),
		.MinDepth = 0.0f,
		.MaxDepth = 1.0f,
	};

	mDxScissorRect = {
		.left = 0,
		.top = 0,
		.right = mWidth,
		.bottom = mHeight
	};
}

void Viewport::CreateDepthStencilBuffer()
{
	D3D12_RESOURCE_DESC depthStencilDesc{
		.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D,
		.Alignment = 0,
		.Width = mWidth,
		.Height = mHeight,
		.DepthOrArraySize = 1, // How many textures in this case
		.MipLevels = 1,
		.Format = DXGI_FORMAT_R24G8_TYPELESS,
		.SampleDesc = {
			.Count = 1,
			.Quality = 0
		},
		.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN,
		.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL,
	};

	D3D12_CLEAR_VALUE optimizedClear{
		.Format = DXGI_FORMAT_D24_UNORM_S8_UINT,
		.DepthStencil = {
			.Depth = 1.0f,
			.Stencil = 0
		}
	};

	mDepthStencilBuffer = std::make_unique<Texture>(mParentDevice, TextureDesc{ depthStencilDesc, optimizedClear });

	D3D12_DEPTH_STENCIL_VIEW_DESC DSVDesc{
		.Format = DXGI_FORMAT_D24_UNORM_S8_UINT,
		.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D,
		.Flags = D3D12_DSV_FLAG_NONE,
		.Texture2D = {
			.MipSlice = 0
		}
	};

	mDepthStencilBuffer->CreateDepthStencilView(mParentDevice, DSVDesc);

	auto DSBarrier = CD3DX12_RESOURCE_BARRIER::Transition(
		mDepthStencilBuffer->GetDxResource(),
		D3D12_RESOURCE_STATE_COMMON,
		D3D12_RESOURCE_STATE_DEPTH_WRITE
	);

	ensure(mParentDevice.GetDxDevice());
	auto& directContext = mParentDevice.GetDirectContext();
	ensure(directContext);

	directContext->GetDxCommandList()->ResourceBarrier(1, &DSBarrier);

}

D3D12_CPU_DESCRIPTOR_HANDLE Viewport::GetCurrentBackBufferView() const
{
	return mBackBuffers[mCurrentBackBufferIndex]->GetRenderTargetView()->GetCPUDescriptorHandle();
}
