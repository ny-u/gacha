/**
* @file: PonkoEngine.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: starting point of the game
*/

#include "pch.h"
#include "PonkoEngine.h"
#include "Window.h"

PonkoEnv::PK_Window PonkoEnv::PK_Window::s_Instance;
SDL_Window* window{};

namespace PonkoEnv
{
	void PonkoEngine::Init()
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		PonkoEnv::PK_Window::GetInstance().ConstructWindow("Help", 800, 600);
		window = PonkoEnv::PK_Window::GetInstance().GetSDLWindow();
	}

	void PonkoEngine::Update()
	{
		SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

		SDL_RenderClear(render);

		SDL_RenderPresent(render);

		SDL_Delay(900);
	}

	void PonkoEngine::Terminate()
	{

	}
}

