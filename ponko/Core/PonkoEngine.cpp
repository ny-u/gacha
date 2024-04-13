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
		PonkoEnv::PK_Window::Get().ConstructWindow(PK_WINDOW_TITLE, PK_WINDOW_WIDTH, PK_WINDOW_HEIGHT);
		window = PonkoEnv::PK_Window::Get().GetSDLWindow();
	}

	void PonkoEngine::Update()
	{
		SDL_PollEvent(PonkoEnv::InputHandler::Get());
		GameStateManager::Update();
	}

	void PonkoEngine::Terminate()
	{
		GameStateManager::Terminate();
	}
}

