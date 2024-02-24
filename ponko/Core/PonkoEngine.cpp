/**
################################################################################
* @author: weijie
* @date: 25 feb 2024
* @brief: starting point of the game
################################################################################
*/

#include "pch.h"
#include "PonkoEngine.h"
#include "Window.h"

static PonkoEnv::PK_Window* pkWindow;

namespace PonkoEnv
{
	void PonkoEngine::Init()
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		

		SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

		SDL_RenderClear(render);

		SDL_RenderPresent(render);

		SDL_Delay(9000);
	}

	void PonkoEngine::Update()
	{

	}

	void PonkoEngine::Terminate()
	{

	}
}

