#include "Adapter.h"
#include "App.h"
#include "BindingContext.h"
#include "Camera.h"
#include "Chunk.h"
#include "DescriptorHeap.h"
#include "Device.h"
#include "DLog.h"
#include "DxUtil.h"
#include "InputAction.h"
#include "InputManager.h"
#include "InputModifier.h"
#include "InputTrigger.h"
#include "Player.h"
#include "Renderer.h"
#include "RenderResource.h"
#include "ResourceManager.h"
#include "Types.h"
#include "Viewport.h"
#include "Window.h"
#include "World.h"
#include <array>
#include <CommandContext.h>
#include <d3d12.h>
#include <d3d12sdklayers.h>
#include <d3dx12.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#include <DirectXMathConvert.inl>
#include <DirectXMathMatrix.inl>
#include <dxgiformat.h>
#include <format>
#include <hidusage.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <Windows.h>
#include <wrl/client.h>

using namespace DirectX;
using Microsoft::WRL::ComPtr;

struct PassConstants
{
	DirectX::XMFLOAT4X4 viewProj = DxUtil::Identity4x4();
};

struct ObjectConstants
{
	DirectX::XMFLOAT4X4 worldMatrix = DxUtil::Identity4x4();
};

static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return App::Get().MsgProc(hWnd, msg, wParam, lParam);
}

[[nodiscard]] static constexpr EKey TranslateVK(UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
	{
		switch (wParam)
		{
			// Letters
		case 'A': return EKey::A;
		case 'B': return EKey::B;
		case 'C': return EKey::C;
		case 'D': return EKey::D;
		case 'E': return EKey::E;
		case 'F': return EKey::F;
		case 'G': return EKey::G;
		case 'H': return EKey::H;
		case 'I': return EKey::I;
		case 'J': return EKey::J;
		case 'K': return EKey::K;
		case 'L': return EKey::L;
		case 'M': return EKey::M;
		case 'N': return EKey::N;
		case 'O': return EKey::O;
		case 'P': return EKey::P;
		case 'Q': return EKey::Q;
		case 'R': return EKey::R;
		case 'S': return EKey::S;
		case 'T': return EKey::T;
		case 'U': return EKey::U;
		case 'V': return EKey::V;
		case 'W': return EKey::W;
		case 'X': return EKey::X;
		case 'Y': return EKey::Y;
		case 'Z': return EKey::Z;

			// Numbers
		case '0': return EKey::Num0;
		case '1': return EKey::Num1;
		case '2': return EKey::Num2;
		case '3': return EKey::Num3;
		case '4': return EKey::Num4;
		case '5': return EKey::Num5;
		case '6': return EKey::Num6;
		case '7': return EKey::Num7;
		case '8': return EKey::Num8;
		case '9': return EKey::Num9;

			// Function keys
		case VK_F1:  return EKey::F1;
		case VK_F2:  return EKey::F2;
		case VK_F3:  return EKey::F3;
		case VK_F4:  return EKey::F4;
		case VK_F5:  return EKey::F5;
		case VK_F6:  return EKey::F6;
		case VK_F7:  return EKey::F7;
		case VK_F8:  return EKey::F8;
		case VK_F9:  return EKey::F9;
		case VK_F10: return EKey::F10;
		case VK_F11: return EKey::F11;
		case VK_F12: return EKey::F12;

			// Arrows
		case VK_UP:    return EKey::ArrowUp;
		case VK_DOWN:  return EKey::ArrowDown;
		case VK_LEFT:  return EKey::ArrowLeft;
		case VK_RIGHT: return EKey::ArrowRight;

			// Control keys
		case VK_ESCAPE:  return EKey::Escape;
		case VK_TAB:     return EKey::Tab;
		case VK_CAPITAL: return EKey::CapsLock;
		case VK_SPACE:   return EKey::Space;
		case VK_RETURN:  return EKey::Enter;
		case VK_BACK:    return EKey::Backspace;
		case VK_SHIFT:
			return (lParam & 0x01000000) ? EKey::RightShift : EKey::LeftShift;
		case VK_CONTROL:
			return (lParam & 0x01000000) ? EKey::RightCtrl : EKey::LeftCtrl;
		case VK_MENU: // Alt
			return (lParam & 0x01000000) ? EKey::RightAlt : EKey::LeftAlt;

			// Other keys
		case VK_INSERT:   return EKey::Insert;
		case VK_DELETE:   return EKey::Delete;
		case VK_HOME:     return EKey::Home;
		case VK_END:      return EKey::End;
		case VK_PRIOR:    return EKey::PageUp;
		case VK_NEXT:     return EKey::PageDown;
		case VK_SNAPSHOT: return EKey::PrintScreen;
		case VK_SCROLL:   return EKey::ScrollLock;
		case VK_PAUSE:    return EKey::PauseBreak;
		case VK_LWIN:     return EKey::LeftWindows;
		case VK_RWIN:     return EKey::RightWindows;

		default: return EKey::Unknown;
		}
	}

	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP: return EKey::MouseLeft;

	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP: return EKey::MouseRight;

	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP: return EKey::MouseMiddle;

	case WM_XBUTTONDOWN:
	case WM_XBUTTONUP:
	{
		if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1) return EKey::MouseButton1;
		if (GET_XBUTTON_WPARAM(wParam) == XBUTTON2) return EKey::MouseButton2;
		return EKey::Unknown;
	}

	case WM_MOUSEWHEEL:
	{
		auto delta = GET_WHEEL_DELTA_WPARAM(wParam);
		return (delta > 0) ? EKey::MouseWheelUp : EKey::MouseWheelDown;
	}
	}

	return EKey::Unknown;
}

App::App()
	:
	mHndAppInst(GetModuleHandle(nullptr)),
	mMainWindow()
{
	ensure(sInstance == nullptr);
	sInstance = this;
}

App::~App()
{
	mWorld.Shutdown();
	mPlayer.reset();
	// Ensure GPU finished work before releasing resources.
	if (mAdapter)
	{
		mAdapter->GetDevice().FlushCommandQueue();
	}
	sInstance = nullptr;
}

bool App::Init()
{
	ensure(!mInitialized);

	if (!InitDirectX())
	{
		return false;
	}

	if (!InitMainWindow())
	{
		return false;
	}


	const Vector3D startPosition = Vector3D{ 0.0f, 110.0f, 0.0f };

	mWorld.Init(startPosition);
	mPlayer = std::make_unique<Player>(startPosition, &mWorld);

	//mDefaultCamera = std::make_unique<Camera>(static_cast<float>(mClientWidth) / static_cast<float>(mClientHeight), Vector3D{ 0.0f, 110.0f, 0.0f });



	SetActiveCamera(mPlayer->GetFPSCamera());
	mInputManager.ActivateContext(mPlayer->GetInputBindings());

	LockCursorToWindowCenter(mMainWindow->GetWindowHandle());

	OnResize();

	//SetupDefaultKeyBindings();

	mInitialized = true;
	return true;
}

bool App::InitMainWindow()
{
	Window::RegisterWindowClass(WindowProc);

	WindowConfig config{
		.width = mClientWidth,
		.height = mClientHeight,
		.title = mWindowTitle
	};

	mMainWindow = std::make_unique<Window>(config);

	RAWINPUTDEVICE rid{
		.usUsagePage = HID_USAGE_PAGE_GENERIC,
		.usUsage = HID_USAGE_GENERIC_MOUSE,
		.dwFlags = RIDEV_INPUTSINK, // Receive input even when not focused
		.hwndTarget = mMainWindow->GetWindowHandle()
	};

	RegisterRawInputDevices(&rid, 1, sizeof(rid));

	return true;
}

LRESULT App::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
#define WM_CUSTOM_DEFFERED_ACTIVATE (WM_APP + 1)

	switch (msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	case WM_CUSTOM_DEFFERED_ACTIVATE:
	{
		if (LOWORD(wParam) == WA_ACTIVE || LOWORD(wParam) == WA_CLICKACTIVE)
		{
			if (!mResizing)
			{
				OnFocusGained();
			}
		}
		else if (LOWORD(wParam) == WA_INACTIVE)
		{
			OnFocusLost();
		}

		return 0;
	}

	case WM_ACTIVATE:
	{
		PostMessage(hWnd, WM_CUSTOM_DEFFERED_ACTIVATE, wParam, 0);
		return 0;
	}

	case WM_ENTERSIZEMOVE:
	{
		mResizing = true;
		OnFocusLost();
		return 0;
	}

	case WM_EXITSIZEMOVE:
	{
		mResizing = false;
		OnResize();
		PostMessage(hWnd, WM_CUSTOM_DEFFERED_ACTIVATE, WA_ACTIVE, 0);
		return 0;
	}

	case WM_SIZE:
	{
		mClientWidth = LOWORD(lParam);
		mClientHeight = HIWORD(lParam);

		// Ignore any WM_SIZE messages before the App is initialized,
		// as we cannot properly execute the resize code before DirectX
		// has been setup
		if (!mInitialized)
			return 0;

		if (wParam == SIZE_MINIMIZED)
		{
			mMinimized = true;
			mMaximized = false;
			OnFocusLost();
		}
		else if (wParam == SIZE_MAXIMIZED)
		{
			mMinimized = false;
			mMaximized = true;
			OnResize();
			OnFocusGained();
		}
		else if (wParam == SIZE_RESTORED)
		{
			// Restoring from minimized state
			if (mMinimized)
			{
				mMinimized = false;
				OnResize();
				OnFocusGained();
			}
			// Restoring from maximized state
			else if (mMaximized)
			{
				mMaximized = false;
				OnResize();
				OnFocusGained();
			}
			// User resizing the app window
			else if (mResizing)
			{
				// Wait until the resizing is done (WM_EXITSIZEMOVE message)
			}
			// API calls (e.g. Win + Arrow keys combinations)
			else
			{
				OnResize();
				PostMessage(hWnd, WM_CUSTOM_DEFFERED_ACTIVATE, WA_ACTIVE, 0);
			}
		}
		return 0;
	}


	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_XBUTTONDOWN:
	case WM_SYSKEYDOWN:
	case WM_KEYDOWN:
	{
		SetCapture(mMainWindow->GetWindowHandle());
		mInputManager.ProcessKeyEvent({ TranslateVK(msg, wParam, lParam), 1.0f });
		return 0;
	}

	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
	case WM_XBUTTONUP:
	case WM_SYSKEYUP:
	case WM_KEYUP:
	{
		ReleaseCapture();
		mInputManager.ProcessKeyEvent({ TranslateVK(msg, wParam, lParam), 0.0f });
		return 0;
	}

	case WM_MOUSEWHEEL:
	case WM_MOUSEHWHEEL:
	{
		return 0; // TODO: Implement mouse wheel support
	}

	case WM_INPUT:
	{
		// Find out the size of input data
		UINT dwSize = 0;
		GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, nullptr, &dwSize, sizeof(RAWINPUTHEADER));

		if (dwSize > 0)
		{
			LPBYTE lpb = new BYTE[dwSize];
			if (lpb && GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER)) == dwSize)
			{
				RAWINPUT* raw = reinterpret_cast<RAWINPUT*>(lpb);
				if (raw->header.dwType == RIM_TYPEMOUSE)
				{
					LONG dx = raw->data.mouse.lLastX;
					LONG dy = raw->data.mouse.lLastY;
					// TODO: Consider combining XY into one event
					if (dx != 0)
					{
						mInputManager.ProcessKeyEvent({ EKey::MouseX, static_cast<float>(dx) });
					}

					if (dy != 0)
					{
						mInputManager.ProcessKeyEvent({ EKey::MouseY, static_cast<float>(dy) });
					}
				}
			}
			delete[] lpb;
			return 0;
		}
		break;
	}
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);

#undef WM_CUSTOM_DEFFERED_ACTIVATE
}

bool App::InitDirectX()
{
#ifdef DEBUG
	{
		Microsoft::WRL::ComPtr<ID3D12Debug> debugController;
		DxCall(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)));
		debugController->EnableDebugLayer();
	}
#endif

	mAdapter = std::make_unique<Adapter>();
	const AdapterInfo& adapterInfo = mAdapter->GetAdapterInfo();

	DLog::Log(
		"Adapter Info:\n"
		"  Name: {}\n"
		"  Dedicated Video Memory: {} MB\n"
		"  Dedicated System Memory : {} MB\n"
		"  Shared System Memory : {} MB",
		adapterInfo.deviceName,
		adapterInfo.GetDedicatedVideoMemoryMB(),
		adapterInfo.GetDedicatedSystemMemoryMB(),
		adapterInfo.GetSharedSystemMemoryMB()
	);

	for (FrameResource& frameRes : mFrameResources)
	{
		frameRes.commandContext = mAdapter->GetDevice().ObtainCommandContext();
		frameRes.passConstantsCB = std::make_unique<ConstantBuffer>(mAdapter->GetDevice(), 1, static_cast<uint32>(sizeof(PassConstants)));
	}
	mChunkRenderer = std::make_unique<ChunkRenderer>(mAdapter->GetDevice());

	Device& device = mAdapter->GetDevice();

	// Execute the initialization commands.
	device.SubmitCommandContext(device.GetDirectContext());

	// Wait until initialization is complete.
	device.FlushCommandQueue();

	return true;
}

void App::SetupDefaultKeyBindings()
{
	mQuitAction = std::make_shared<InputAction>("Quit");
	mWalkAction = std::make_shared<InputAction>("Walk", EActionValueType::Vector2D);
	mLookAction = std::make_shared<InputAction>("Look", EActionValueType::Vector2D);
	mShiftKeyAction = std::make_shared<InputAction>("ShiftModifier");
	mRightClickAction = std::make_shared<InputAction>("RightClick");
	mVerticalMoveAction = std::make_shared<InputAction>("VerticalMove", EActionValueType::Vector1D);

	mDefaultControls = std::make_shared<BindingContext>(
		ActionMapping{
			mWalkAction, {
				Mapping{
					EKey::W,
					{ Modifiers::ReorderAxes(Axes::YXZ) },
					{ }
				},
				Mapping{
					EKey::S,
					{ Modifiers::ReorderAxes(Axes::YXZ), Modifiers::Negate(false, true, false) },
					{ }
				},
				Mapping{
					EKey::A,
					{ Modifiers::Negate(true, false, false) },
					{ }
				},
				Mapping{
					EKey::D,
					{ },
					{ }
				}
			},
		},
		ActionMapping{
			mQuitAction, {
				Mapping{
					EKey::Escape,
					{ },
					{ }
				}
			}
		},
		ActionMapping{
			mRightClickAction, {
				Mapping{
					EKey::MouseRight,
					{ },
					{ }
				}
			}
		},
		ActionMapping{
			mLookAction, {
				Mapping{
					EKey::MouseX,
					{ },
					{ Triggers::ChordAction(mRightClickAction) }
				},
				Mapping{
					EKey::MouseY,
					{ Modifiers::ReorderAxes(Axes::YXZ) },
					{ Triggers::ChordAction(mRightClickAction)}
				}
			}
		},
		ActionMapping{
			mVerticalMoveAction, {
				Mapping{
					EKey::LeftShift,
					{ Modifiers::Negate() },
					{ }
				},
				Mapping{
					EKey::Space,
					{ },
					{ }
				}
			}
		}
	);

	mInputManager.ActivateContext(mDefaultControls);

	mRightClickAction->BindCallback(
		EActionState::Started,
		[this]()
		{
			POINT mousePos;
			GetCursorPos(&mousePos);

			RECT clipRect{
				.left = mousePos.x,
				.top = mousePos.y,
				.right = mousePos.x + 1,
				.bottom = mousePos.y + 1
			};

			ClipCursor(&clipRect);
			ShowCursor(FALSE);
		}
	);
	mRightClickAction->BindCallback(
		EActionState::Completed,
		[this]()
		{
			ClipCursor(nullptr);
			ShowCursor(TRUE);
		}
	);

	mWalkAction->BindCallback(
		EActionState::Triggered,
		[this](InputActionValue value, float deltaSeconds)
		{
			constexpr float moveSpeed = 20.0f;

			auto vec2 = value.Get<Vector2D>();

			if (vec2.LengthSquared() > 1)
			{
				vec2.Normalize();
			}

			vec2 = vec2 * deltaSeconds * moveSpeed;
			mDefaultCamera->Translate(vec2.x, 0.0f, vec2.y);
		}
	);

	mQuitAction->BindCallback(
		EActionState::Started,
		[]()
		{
			PostQuitMessage(0);
		}
	);

	mLookAction->BindCallback(
		EActionState::Triggered,
		[this](InputActionValue value)
		{
			//constexpr float sensitivity = 2.0f;
			const auto vec2 = value.Get<Vector2D>();

			const float yaw = XMConvertToRadians(vec2.x);
			const float pitch = XMConvertToRadians(vec2.y);

			mDefaultCamera->Rotate(pitch, yaw);
		}
	);

	mVerticalMoveAction->BindCallback(
		EActionState::Triggered,
		[this](InputActionValue value, float deltaSeconds)
		{
			constexpr float moveSpeed = 10.0f;
			const auto vec1 = value.Get<Vector1D>() * deltaSeconds * moveSpeed;

			mDefaultCamera->SetPosition(mDefaultCamera->GetPosition() + Vector3D(0.0f, vec1, 0.0f));

			//mDefaultCamera->Translate(0.0f, vec1, 0.0f);
		}
	);
}

App& App::Get() noexcept
{
	return *sInstance;
}

int32 App::Run()
{
	mAppTimer.Reset();

	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if (!mAppPaused)
		{
			mAppTimer.Tick();
			const float deltaSeconds = mAppTimer.DeltaSeconds();

			CalculateFrameStats();
			mInputManager.Update(deltaSeconds);
			Update(deltaSeconds);
			Draw(deltaSeconds);
		}
		else
		{
			Sleep(100);
		}
	}

	return static_cast<int32>(msg.wParam);
}

void App::Update(float deltaSeconds)
{
	mCurrentFrameResourceIndex = (mCurrentFrameResourceIndex + 1) % mFrameResources.size();
	FrameResource& currentFrameResource = mFrameResources[mCurrentFrameResourceIndex];
	Device& device = mAdapter->GetDevice();

	// If the GPU has not yet processed the current frame resource, wait
	if (currentFrameResource.fenceValue != 0 && device.GetCompletedFenceValue() < currentFrameResource.fenceValue)
	{
		HANDLE eventHandle = CreateEventEx(NULL, NULL, 0, EVENT_ALL_ACCESS);
		ensure(eventHandle);

		device.SetFenceEvent(currentFrameResource.fenceValue, eventHandle);

		WaitForSingleObject(eventHandle, INFINITE);
		CloseHandle(eventHandle);
	}

	//DLog::Log("GPU frame time for ind = {}, {}", mCurrentFrameResourceIndex, device.GetFrameTime(mCurrentFrameResourceIndex * 2));
	auto& commandContext = currentFrameResource.commandContext;
	commandContext->Reset();

	commandContext->GetDxCommandList()->EndQuery(device.GetDxQueryHeap(), D3D12_QUERY_TYPE_TIMESTAMP, mCurrentFrameResourceIndex * 2);

	UpdateActiveCamera();
	UpdateWorld();
	UpdatePlayer(deltaSeconds);

	const uint64 completedFenceValue = device.GetCompletedFenceValue();
	mResourceManager.ProcessPendingDeletes(completedFenceValue);
}

void App::UpdateActiveCamera()
{
	XMFLOAT4X4 cameraView = mActiveCamera->GetViewMatrix();
	XMFLOAT4X4 cameraProj = mActiveCamera->GetProjectionMatrix();

	XMMATRIX view = XMLoadFloat4x4(&cameraView);
	XMMATRIX proj = XMLoadFloat4x4(&cameraProj);
	XMMATRIX viewProj = view * proj;

	// Update the pass constant buffer with the latest viewProj matrix.
	PassConstants passConstants;
	DirectX::XMStoreFloat4x4(&passConstants.viewProj, DirectX::XMMatrixTranspose(viewProj));

	FrameResource& currentFrameResource = GetCurrentFrameResource();
	currentFrameResource.passConstantsCB->UpdateBufferData(&passConstants, sizeof(passConstants));
}

void App::UpdateWorld()
{
	Device& device = mAdapter->GetDevice();
	auto& commandContext = GetCurrentFrameResource().commandContext;

	mWorld.Update(mPlayer->GetPosition());
	mChunkRenderData.clear();

	for (auto& chunk : mWorld.GetChunks())
	{
		ensure(chunk);

		RenderData* chunkRenderData = chunk->GetRenderData();
		if (chunk->IsRenderDataDirty())
		{
			if (!chunkRenderData)
			{
				std::unique_ptr<RenderData> renderData = std::make_unique<RenderData>();

				std::unique_ptr<ConstantBuffer> constantBuffer = std::make_unique<ConstantBuffer>(mAdapter->GetDevice(), 1, static_cast<uint32>(sizeof(ObjectConstants)));
				ObjectConstants chunkConstants;
				XMMATRIX chunkWorldMatrix = XMLoadFloat4x4(&chunk->GetWorldMatrix());
				DirectX::XMStoreFloat4x4(&chunkConstants.worldMatrix, DirectX::XMMatrixTranspose(chunkWorldMatrix));
				constantBuffer->UpdateBufferData(&chunkConstants, sizeof(ObjectConstants));
				renderData->SetConstantBuffer(std::move(constantBuffer));

				chunk->SetRenderData(std::move(renderData));
				chunkRenderData = chunk->GetRenderData();
			}

			const auto chunkMeshData = chunk->GetMeshData();
			ensure(chunkMeshData);

			std::unique_ptr<VertexBuffer> vertexBuffer = std::make_unique<VertexBuffer>(device, chunkMeshData->vertices.size() * sizeof(BlockVertex), static_cast<uint32>(sizeof(BlockVertex)));
			vertexBuffer->UploadBufferData<BlockVertex>(commandContext.get(), chunkMeshData->vertices);

			std::unique_ptr<IndexBuffer> indexBuffer = std::make_unique<IndexBuffer>(device, chunkMeshData->indices.size() * sizeof(uint32), DXGI_FORMAT_R32_UINT);
			indexBuffer->UploadBufferData<uint32>(commandContext.get(), chunkMeshData->indices);

			chunkRenderData->SetVertexBuffer(std::move(vertexBuffer));
			chunkRenderData->SetIndexBuffer(std::move(indexBuffer));

			chunk->SetIsRenderDataDirty(false);
		}

		if (chunkRenderData)
		{
			mChunkRenderData.push_back(chunkRenderData);
		}
	}
	ensure(mChunkRenderData.size() <= mWorld.GetChunks().size());
}

void App::UpdatePlayer(float deltaSeconds)
{
	if (!mWorld.IsInitialized())
	{
		return;
	}

	{
		constexpr float tickTime = 1.0f / 20.0f;
		static float accumulatedTime = 0.0f;

		accumulatedTime += deltaSeconds;

		while (accumulatedTime >= tickTime)
		{
			mPlayer->Tick();

			accumulatedTime -= tickTime;
		}

		mPlayer->UpdateCamera(accumulatedTime / tickTime, deltaSeconds);
	}
}

void App::Draw(float deltaSeconds)
{
	Device& device = mAdapter->GetDevice();
	DescriptorHeapManager& descriptorHeapManager = device.GetDescriptorHeapManager();
	FrameResource& currentFrameRes = GetCurrentFrameResource();
	auto& commandContext = currentFrameRes.commandContext;

	ensure(commandContext);

	ID3D12GraphicsCommandList* dxCommandList = commandContext->GetDxCommandList();

	ID3D12Resource* currentBackBuffer = mMainWindow->GetViewport().GetCurrentBackBufferResource();
	D3D12_CPU_DESCRIPTOR_HANDLE currentBackBufferView = mMainWindow->GetViewport().GetCurrentBackBufferView();
	D3D12_CPU_DESCRIPTOR_HANDLE depthStencilView = mMainWindow->GetViewport().GetDepthStencilView();


	auto presentRenderTargetTransition = CD3DX12_RESOURCE_BARRIER::Transition(
		currentBackBuffer,
		D3D12_RESOURCE_STATE_PRESENT,
		D3D12_RESOURCE_STATE_RENDER_TARGET
	);

	dxCommandList->ResourceBarrier(1, &presentRenderTargetTransition);

	auto viewport = mMainWindow->GetViewport().GetDxViewport();
	auto scissorRect = mMainWindow->GetViewport().GetDxScissorRect();

	dxCommandList->RSSetViewports(1, &viewport);
	dxCommandList->RSSetScissorRects(1, &scissorRect);

	dxCommandList->ClearRenderTargetView(
		currentBackBufferView,
		DirectX::Colors::CadetBlue,
		0,
		nullptr
	);

	dxCommandList->ClearDepthStencilView(
		depthStencilView,
		D3D12_CLEAR_FLAG_DEPTH | D3D12_CLEAR_FLAG_STENCIL,
		1.0f,
		0,
		0,
		nullptr
	);

	dxCommandList->OMSetRenderTargets(
		1,
		&currentBackBufferView,
		true,
		&depthStencilView
	);


	std::array descriptorHeaps = { descriptorHeapManager.GetDescriptorHeap(EDescriptorHeapType::GeneralGPUVisible).GetDxHeap() };
	dxCommandList->SetDescriptorHeaps(static_cast<uint32>(descriptorHeaps.size()), descriptorHeaps.data());

	currentFrameRes.fenceValue = device.GetCurrentFenceValue() + 1; // This will need to be reworked if multi-threading command list submission.


	mChunkRenderer->Draw(currentFrameRes, mChunkRenderData);

	auto renderTargetPresentTransition = CD3DX12_RESOURCE_BARRIER::Transition(
		currentBackBuffer,
		D3D12_RESOURCE_STATE_RENDER_TARGET,
		D3D12_RESOURCE_STATE_PRESENT
	);

	dxCommandList->ResourceBarrier(1, &renderTargetPresentTransition);

	dxCommandList->EndQuery(device.GetDxQueryHeap(), D3D12_QUERY_TYPE_TIMESTAMP, mCurrentFrameResourceIndex * 2 + 1);
	dxCommandList->ResolveQueryData(
		device.GetDxQueryHeap(),
		D3D12_QUERY_TYPE_TIMESTAMP,
		mCurrentFrameResourceIndex * 2,
		2,
		device.GetDxQueryBuffer(),
		sizeof(UINT64) * mCurrentFrameResourceIndex * 2
	);

	device.SubmitCommandContext(commandContext);
	device.SignalFence(); // This will need to be reworked if multi-threading command list submission.

	mMainWindow->DrawViewport();
}

void App::CalculateFrameStats()
{
	static uint64 frameCount = 0;
	static float elapsedTime = 0.0f;

	frameCount++;

	if ((mAppTimer.TotalSeconds() - elapsedTime) >= 1.0)
	{
		float fps = static_cast<float>(frameCount); // fps = frameCount / (1 second) 
		float mspf = 1000.0f / fps; // miliseconds per frame

		std::wstring windowTitle = std::format(L"{}\t FPS: {} | ms: {} \t{}", mWindowTitle.c_str(), std::to_wstring(frameCount), std::to_wstring(mspf), GetDebugInfo());
		SetWindowText(mMainWindow->GetWindowHandle(), windowTitle.c_str());

		frameCount = 0;
		elapsedTime += 1.0f;
	}
}

std::wstring App::GetDebugInfo()
{
	const Vector3D playerPos = mPlayer->GetPosition();

	return std::format(L"Position: ({:.2f}, {:.2f}, {:.2f})", playerPos.x, playerPos.y, playerPos.z);
}

void App::AppPause()
{
	if (!mAppPaused)
	{
		mAppPaused = true;
		mAppTimer.Pause();
	}
}

void App::AppUnpause()
{
	if (mAppPaused)
	{
		mAppPaused = false;
		mAppTimer.Start();
	}
}

void App::OnResize()
{
	Device& device = mAdapter->GetDevice();

	// We have to flush before reseting any resources
	device.FlushCommandQueue();

	auto& directContext = device.GetDirectContext();
	directContext->Reset();

	mMainWindow->OnResize(mClientWidth, mClientHeight);

	// Submit resize work and wait untill it is complete
	device.SubmitCommandContext(directContext);
	device.FlushCommandQueue();

	mActiveCamera->SetAspectRatio(static_cast<float>(mClientWidth) / static_cast<float>(mClientHeight));
}

void App::OnFocusLost()
{
	mFocused = false;

	UnlockCursor();
	mInputManager.ClearInputs();
	AppPause();
}

void App::OnFocusGained()
{
	mFocused = true;

	if (mMainWindow)
	{
		LockCursorToWindowCenter(mMainWindow->GetWindowHandle());
	}
	AppUnpause();
}

void App::SetActiveCamera(Camera& camera)
{
	mActiveCamera = &camera;
	mActiveCamera->SetAspectRatio(static_cast<float>(mClientWidth) / static_cast<float>(mClientHeight));
}

void App::LockCursorToWindowCenter(HWND windowHandle) const
{
	RECT clientRect;
	GetClientRect(windowHandle, &clientRect);

	POINT clientCenter{
		.x = (clientRect.right - clientRect.left) / 2,
		.y = (clientRect.bottom - clientRect.top) / 2
	};

	ClientToScreen(windowHandle, &clientCenter);
	SetCursorPos(clientCenter.x, clientCenter.y);


	RECT clipRect{
		.left = clientCenter.x,
		.top = clientCenter.y,
		.right = clientCenter.x + 1,
		.bottom = clientCenter.y + 1
	};
	ClipCursor(&clipRect);
}

void App::UnlockCursor() const
{
	ClipCursor(nullptr);
}
