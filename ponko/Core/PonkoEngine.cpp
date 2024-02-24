/**
################################################################################
* @author: weijie
* @date: 25 feb 2024
* @brief: starting point of the game
################################################################################
*/

#include "pch.h"
#include "PonkoEngine.h"

namespace PonkoEnv
{
	void PonkoEngine::Init()
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		SDL_Window* window = SDL_CreateWindow("Is All Orge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
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

