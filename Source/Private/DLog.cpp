#include "DLog.h"
#include "DxUtil.h"
#include "Types.h"
#include <cstdio>
#include <iostream>
#include <string_view>
#include <Windows.h>

static constexpr uint16 LOG_DISPLAY_COLOR = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
static constexpr uint16 WARNING_DISPLAY_COLOR = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
static constexpr uint16 ERROR_DISPLAY_COLOR = FOREGROUND_RED | FOREGROUND_INTENSITY;

static uint32 sMainThreadID = 0;

// Console control handler: forward quit to main thread so app can clean up
static BOOL WINAPI ConsoleCtrlHandler(DWORD ctrlType)
{
	switch (ctrlType)
	{
	case CTRL_C_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_LOGOFF_EVENT:
	case CTRL_SHUTDOWN_EVENT:
	{
		if (sMainThreadID != 0)
		{
			DLog::Shutdown();
			PostThreadMessage(sMainThreadID, WM_QUIT, 0, 0);
		}
		return TRUE;
	}		
	}

	return FALSE;
}

void DLog::Init()
{
	ensure(sHndConsole == nullptr);

	sMainThreadID = GetCurrentThreadId();

	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);

	sHndConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCtrlHandler(ConsoleCtrlHandler, TRUE);
}

void DLog::Shutdown()
{
	if (sMainThreadID != 0)
	{
		SetConsoleCtrlHandler(ConsoleCtrlHandler, FALSE);
		sMainThreadID = 0;
	}

	if (sHndConsole)
	{
		FreeConsole();
		sHndConsole = nullptr;
	}
}

void DLog::Log(std::string_view message)
{
	SetConsoleTextAttribute(sHndConsole, LOG_DISPLAY_COLOR);
	std::cout << message << "\n";
}

void DLog::Warn(std::string_view message)
{
	SetConsoleTextAttribute(sHndConsole, WARNING_DISPLAY_COLOR);
	std::cout << message << "\n";
}

void DLog::Error(std::string_view message)
{
	SetConsoleTextAttribute(sHndConsole, ERROR_DISPLAY_COLOR);
	std::cerr << message << "\n";
}

void DLog::Log(std::wstring_view message)
{
	SetConsoleTextAttribute(sHndConsole, LOG_DISPLAY_COLOR);
	std::wcout << message << "\n";
}

void DLog::Warn(std::wstring_view message)
{
	SetConsoleTextAttribute(sHndConsole, WARNING_DISPLAY_COLOR);
	std::wcout << message << "\n";
}

void DLog::Error(std::wstring_view message)
{
	SetConsoleTextAttribute(sHndConsole, ERROR_DISPLAY_COLOR);
	std::wcerr << message << "\n";
}
