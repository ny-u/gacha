/**
* @file: PonkoEngine.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: starting point of the game
*/

#include "pch.h"
#include "PonkoEngine.h"
#include "GameState/GameStateManager.h"
Manager manager{};
Entity& newPlayer{ manager.addEntity() };
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

		newPlayer.addComponent<TransformComp>();
		newPlayer.getComponent<TransformComp>().GetPos().x = 100;

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

