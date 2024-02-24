#include "pch.h"
#include "Window.h"

PonkoEnv::PK_Window::PK_Window(	const char* _title,
								int const& _width,
								int const& _height)
	: m_windowTitle{_title}, m_windowWidth{ _width }, m_windowHeight{_height}
{
	sdl_Window = SDL_CreateWindow(	m_windowTitle,
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									m_windowWidth, m_windowHeight,
									SDL_WINDOW_SHOWN);
}