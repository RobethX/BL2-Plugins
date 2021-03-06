#include "stdafx.h"
#include "menu.h"
#include "tools.h"
#include <iostream>
#include <string>
#include <overlay.h>

Menu * menu;

DWORD WINAPI OnDllAttach(LPVOID lpParam)
{
	if (WaitForModules(10000, { L"d3d9.dll", L"PhysXLoader.dll" }) == WAIT_TIMEOUT) {
		// One or more modules were not loaded in time
		return FALSE;
	}

	//MessageBox(0, "Robeth's Fun Menu for Borderlands 2 loaded successfully", "Hello, World!", MB_ICONEXCLAMATION | MB_OK);

	SetParam("process", "Borderlands2.exe");

	struct draw {
		draw() : id(TextCreate("Arial", 10, false, false, 20, 20, 0xFF6432ff, "", false, true)) { }
		~draw() { TextDestroy(id); }

		int id;
	} draw;

	//menu = new Menu(); //init menu

	while (true) { //debug
		//Sleep(1000);
		//menu->draw();
		TextSetString(draw.id, "Robeth's Fun Menu for Borderlands 2");
	}

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