#include "../Resources/resource.h"
#include "Window.h"
#include <App.h>
#include <dxgiformat.h>
#include <format>
#include <memory>
#include <Types.h>
#include <Viewport.h>
#include <Windows.h>
#include "DxUtil.h"

Window::Window(const WindowConfig& config, const std::shared_ptr<Window>& parentWindow)
{
	uint32 windowExStyle = 0;
	uint32 windowStyle = WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

	if (!config.hasOSBorder)
	{
		windowExStyle = WS_EX_WINDOWEDGE;

		windowStyle = WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
		if (config.appearsInTaskbar)
		{
			windowExStyle |= WS_EX_APPWINDOW;
		}
		else
		{
			windowExStyle |= WS_EX_TOOLWINDOW;
		}

		if (!config.acceptsInput)
		{
			windowExStyle |= WS_EX_TRANSPARENT;
		}
	}
	else
	{
		windowExStyle = WS_EX_APPWINDOW;
		windowStyle = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_BORDER;

		if (config.supportsMaximize)
		{
			windowStyle |= WS_MAXIMIZEBOX;
		}

		if (config.supportsMinimize)
		{
			windowStyle |= WS_MINIMIZEBOX;
		}

		if (config.userResizeable)
		{
			windowStyle |= WS_THICKFRAME;
		}
	}

	// Desired client rect
	RECT desiredRect = {
		.left = 0,
		.top = 0,
		.right = config.width,
		.bottom = config.height
	};

	mClientWidth = config.width;
	mClientHeight = config.height;
	// Calculate the needed window rect
	AdjustWindowRectEx(&desiredRect, windowStyle, false, windowExStyle);
	mWidth = static_cast<uint16>(desiredRect.right - desiredRect.left);
	mHeight = static_cast<uint16>(desiredRect.bottom - desiredRect.top);
	mPositionX = config.screenPositionX;
	mPositionY = config.screenPositionY;

	mHandle = CreateWindowEx(
		windowExStyle,
		WindowClassName,
		config.title.c_str(),
		windowStyle,
		mPositionX,
		mPositionY,
		mWidth,
		mHeight,
		parentWindow ? parentWindow->GetWindowHandle() : nullptr, //parent
		nullptr, //menu
		GetModuleHandle(nullptr), // instance
		nullptr // lpParam
	);

	ensure(mHandle != NULL);

	if (config.createViewport)
	{
		mViewport = std::make_unique<Viewport>(
			App::Get().GetAdapter(),
			mHandle,
			mClientWidth,
			mClientHeight,
			DXGI_FORMAT_R8G8B8A8_UNORM,
			true // allow tearing
		);
	}

	ShowWindow(mHandle, SW_SHOW);
	UpdateWindow(mHandle);
}

void Window::RegisterWindowClass(WNDPROC msgProc)
{
	const HINSTANCE hInstance = GetModuleHandle(nullptr);
	const HICON wndIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINICON));

	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = msgProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = wndIcon;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = HBRUSH(COLOR_WINDOW + 1);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = Window::WindowClassName;
	wc.hIconSm = wndIcon;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(nullptr, L"Failed to register main window class", L"Error", MB_OK);
	}
}

void Window::DrawViewport()
{
	mViewport->Present();
}

void Window::OnResize(uint16 newClientWidth, uint16 newClientHeight)
{
	mClientWidth = newClientWidth;
	mClientHeight = newClientHeight;

	RECT windowRect;
	GetWindowRect(mHandle, &windowRect);
	mWidth = static_cast<uint16>(windowRect.right - windowRect.left);
	mHeight = static_cast<uint16>(windowRect.bottom - windowRect.top);

	if (mViewport)
	{
		mViewport->OnResize(mClientWidth, mClientHeight);
	}
}
