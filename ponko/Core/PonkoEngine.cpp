/**
* @file: PonkoEngine.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: starting point of the game
*/

#include "pch.h"
#include "PonkoEngine.h"
#include "GameState/GameStateManager.h"

SDL_Window* window{};

namespace PonkoEnv
{
	void PonkoEngine::Init()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		GameStateManager::Init();

		// Create Window
		PonkoEnv::PK_Window::Get().ConstructWindow("Help", 800, 600);
		window = PonkoEnv::PK_Window::Get().GetSDLWindow();
	}

	void PonkoEngine::Update()
	{
		GameStateManager::Update();
	}

	void PonkoEngine::Terminate()
	{
		GameStateManager::Terminate();
	}
}

