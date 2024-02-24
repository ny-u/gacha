/**
* @file: Window.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: window wrapper
*/

#include "pch.h"
#include "Window.h"

PonkoEnv::PK_Window& PonkoEnv::PK_Window::Get()
{
	static PK_Window s_Instance;
	return s_Instance;
}

SDL_Window* PonkoEnv::PK_Window::GetSDLWindow()
{
	return sdl_Window;
}

void PonkoEnv::PK_Window::ConstructWindow(const char* _title,
						int const& _width, int const& _height)
{
	m_windowTitle = _title;
	m_windowWidth = _width;
	m_windowHeight = _height;

	sdl_Window =  SDL_CreateWindow(	m_windowTitle,
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									m_windowWidth, m_windowHeight,
									SDL_WINDOW_SHOWN);
}