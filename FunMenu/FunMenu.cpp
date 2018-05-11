#include "stdafx.h"
#include "menu.h"
#include "tools.h"

Menu * menu;

DWORD WINAPI OnDllAttach(LPVOID lpParam)
{
	if (WaitForModules(10000, { L"d3d9.dll", L"PhysXLoader.dll" }) == WAIT_TIMEOUT) {
		// One or more modules were not loaded in time
		return FALSE;
	}

	menu = new Menu(); //init menu

	menu->draw();

	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DWORD dwThreadId, dwThrdParam = 1;
		HANDLE hThread;
		hThread = CreateThread(NULL, 0, OnDllAttach, &dwThrdParam, 0, &dwThreadId);
	}

	return 1;
}