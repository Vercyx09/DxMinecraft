#include "App.h"
#include <crtdbg.h>
#include "DxUtil.h"
#include "DLog.h"
#include <dxgidebug.h>
#include <dxgi1_3.h>
#include <Windows.h>
#include <wrl/client.h>
#include <sal.h>

int WINAPI WinMain(
	[[maybe_unused]] _In_ HINSTANCE hInstance,
	[[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance,
	[[maybe_unused]] _In_ LPSTR lpCmdLine,
	[[maybe_unused]] _In_ int nCmdShow)
{

#ifdef DEBUG
	// Enable run-time memory check for debug builds.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	DLog::Init();

	try
	{
		{
			App app;

			if (!app.Init())
				return -1;

			app.Run();
		}
#ifdef DEBUG
		// Ask DXGI to print a detailed ReportLiveObjects to the debugger output.
		// This helps identify which D3D12/DXGI objects are still alive at process exit.
		Microsoft::WRL::ComPtr<IDXGIDebug1> dxgiDebug;
		if (SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&dxgiDebug))))
		{
			dxgiDebug->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_DETAIL);
		}
#endif

		return 0;
	}
	catch (DxException& e)
	{
		MessageBox(nullptr, e.ToWString().c_str(), L"DxException", MB_OK);
		return -1;
	}
}