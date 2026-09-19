#pragma once

#define NOMINMAX

#include "Adapter.h"
#include "AppTimer.h"
#include "BindingContext.h"
#include "Core.h"
#include "InputAction.h"
#include "InputManager.h"
#include "Player.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "Types.h"
#include "World.h"
#include <array>
#include <dxgiformat.h>
#include <memory>
#include <string>
#include <vector>
#include <Windows.h>

class Window;
class Camera;
class CommandContext;

class App
{

public:

	App();

	~App();

	App(const App&) = delete;

	App& operator=(const App&) = delete;

	App(App&&) = delete;

	App& operator=(App&&) = delete;

public:

	[[nodiscard]] static App& Get() noexcept;

	bool Init();

	int32 Run();

protected:

	bool InitMainWindow();

	bool InitDirectX();

	void SetupDefaultKeyBindings();

	void Update(float deltaSeconds);

	void UpdateActiveCamera();

	void UpdateWorld();

	void UpdatePlayer(float deltaSeconds);

	void Draw(float deltaSeconds);

	void CalculateFrameStats();

	std::wstring GetDebugInfo();

	void OnResize();

	void OnFocusLost();

	void OnFocusGained();

	void SetActiveCamera(Camera& camera);

public:

	void AppPause();

	void AppUnpause();

	void LockCursorToWindowCenter(HWND windowHandle) const;

	void UnlockCursor() const;

public:

	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:

	[[nodiscard]] FORCEINLINE InputManager& GetInputManager() noexcept { return mInputManager; }

	[[nodiscard]] FORCEINLINE Adapter& GetAdapter() const noexcept { return *mAdapter.get(); }

	[[nodiscard]] FORCEINLINE World& GetWorld() noexcept { return mWorld; }

	[[nodiscard]] FORCEINLINE ResourceManager& GetResourceManager() noexcept { return mResourceManager; }

	[[nodiscard]] FORCEINLINE float GetCurrentSeconds() const noexcept { return mAppTimer.TotalSeconds(); }

	[[nodiscard]] FORCEINLINE FrameResource& GetCurrentFrameResource() { return mFrameResources[mCurrentFrameResourceIndex]; }

public:

	inline static const uint8 NumSwapChainBuffers = 3;

protected:

	std::wstring mWindowTitle = L"DxMinecraft";
	uint16 mClientWidth = 1280;
	uint16 mClientHeight = 720;
	DXGI_FORMAT mBackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
	DXGI_FORMAT mDepthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;

protected:

	HINSTANCE mHndAppInst;

protected:

	std::unique_ptr<Adapter> mAdapter;
	std::unique_ptr<Window> mMainWindow;

protected:

	std::array<FrameResource, NumSwapChainBuffers> mFrameResources;
	std::size_t mCurrentFrameResourceIndex = 0;

protected:

	std::vector<RenderData*> mChunkRenderData;
	std::unique_ptr<ChunkRenderer> mChunkRenderer;

protected:

	AppTimer mAppTimer;

	bool mAppPaused = false;
	bool mMaximized = false;
	bool mMinimized = false;
	bool mResizing = false;
	bool mFocused = false;

	std::unique_ptr<Camera> mDefaultCamera;

	Camera* mActiveCamera = nullptr;

protected:

	bool mInitialized = false;
	inline static App* sInstance = nullptr;

protected:

	InputManager mInputManager;

	std::shared_ptr<InputAction> mQuitAction;
	std::shared_ptr<InputAction> mWalkAction;
	std::shared_ptr<InputAction> mLookAction;
	std::shared_ptr<InputAction> mShiftKeyAction;
	std::shared_ptr<InputAction> mRightClickAction;
	std::shared_ptr<InputAction> mVerticalMoveAction;
	std::shared_ptr<BindingContext> mDefaultControls;

protected:

	ResourceManager mResourceManager;

	World mWorld{ 1337 };

	std::unique_ptr<Player> mPlayer;
};