#include "pch.h"
#include "Window.h"

PonkoEnv::PK_Window PonkoEnv::PK_Window::s_Instance; // define a static member

PonkoEnv::PK_Window& PonkoEnv::PK_Window::GetInstance()
{
	return s_Instance;
}