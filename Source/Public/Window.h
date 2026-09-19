#pragma once
#include "Core.h"
#include "Types.h"
#include <memory>
#include <string>
#include <Windows.h>

class Viewport;

struct WindowConfig
{
	uint16 width = 1280;
	uint16 height = 720;
	uint16 screenPositionX = 100;
	uint16 screenPositionY = 100;
	std::wstring title = L"Application Window";

	bool hasOSBorder = true;
	bool appearsInTaskbar = true;
	bool acceptsInput = true;
	bool userResizeable = true;
	bool supportsMinimize = true;
	bool supportsMaximize = true;
	bool preserveAspectRatio = true;

	bool createViewport = true;
};


class Window
{

public:

	Window(const WindowConfig& config, const std::shared_ptr<Window>& parentWindow = nullptr);

	static void RegisterWindowClass(WNDPROC msgProc);

public:

	void DrawViewport();

	void OnResize(uint16 newClientWidth, uint16 newClientHeight);

#pragma region Getters

public:

	[[nodiscard]] FORCEINLINE HWND GetWindowHandle() const noexcept { return mHandle; }

	[[nodiscard]] FORCEINLINE uint16 GetWidth() const noexcept { return mWidth; }

	[[nodiscard]] FORCEINLINE uint16 GetHeight() const noexcept { return mHeight; }

	[[nodiscard]] FORCEINLINE uint16 GetClientWidth() const noexcept { return mClientWidth; }

	[[nodiscard]] FORCEINLINE uint16 GetClientHeight() const noexcept { return mClientHeight; }

	[[nodiscard]] FORCEINLINE uint16 GetPositionX() const noexcept { return mPositionX; }

	[[nodiscard]] FORCEINLINE uint16 GetPositionY() const noexcept { return mPositionY; }

	[[nodiscard]] FORCEINLINE Viewport& GetViewport() const noexcept { return *mViewport.get(); }

#pragma endregion

protected:

	uint16 mClientWidth;
	uint16 mClientHeight;
	uint16 mWidth;
	uint16 mHeight;
	uint16 mPositionX;
	uint16 mPositionY;
	HWND mHandle;

	std::unique_ptr<Viewport> mViewport;

public:

	inline static const WCHAR* WindowClassName = L"DxMinecraftWindowClass";
};