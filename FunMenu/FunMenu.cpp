#include "stdafx.h"
#include "menu.h"

Menu * menu;

DWORD WINAPI Start(LPVOID lpParam)
{
	menu = new Menu(); //init menu

	/*
	Sleep(2100);
	DWORD target1 = FindPattern(0x400000, 0x500000, pattern1, "xxxxxxxxx", 0);
	DWORD target2 = FindPattern(0x400000, 0x500000, pattern2, "xxxxxx", 0);
	if (target1 == NULL || target2 == NULL)
		return 0;

	DWORD dwProtect;

	BYTE *b = (BYTE*)(target1 + 7);
	VirtualProtect((void*)b, 0x2, PAGE_READWRITE, &dwProtect);
	*b++ = 0x90;
	*b-- = 0x90;
	VirtualProtect((void*)b, 0x2, dwProtect, &dwProtect);

	b = (BYTE*)(target2 + 4);
	VirtualProtect((void*)b, 0x2, PAGE_READWRITE, &dwProtect);
	*b++ = 0x90;
	*b-- = 0x90;
	VirtualProtect((void*)b, 0x2, dwProtect, &dwProtect);
	*/

	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	// Menu Toggle
	//if (GetKeyboardState(VK_INSERT)) { //getkeyboardstate dumps data to array, does not check key
	//menu->toggle();
	//}

	menu->draw();

	if (reason == DLL_PROCESS_ATTACH)
	{
		DWORD dwThreadId, dwThrdParam = 1;
		HANDLE hThread;
		hThread = CreateThread(NULL, 0, Start, &dwThrdParam, 0, &dwThreadId);
	}

	return 1;
}