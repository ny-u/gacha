/**
* @file: main.cpp
* @author: weijie
* @date: 25 feb 2024
* @brief: main 
*/

#include "pch.h"
#include "Core/PonkoEngine.h"
#define _WIN32_WINNT 0x0500
#include<windows.h>    

int main(int argc, char** argv)
{
#if defined(DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

#if defined(RELEASE)
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOW);
#else
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOW);
#endif

	PonkoEnv::PonkoEngine::Init();
	PonkoEnv::PonkoEngine::Update();
	PonkoEnv::PonkoEngine::Terminate();

	return 0;
}