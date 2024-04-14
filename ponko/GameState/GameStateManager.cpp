/**
* @file: GameStateManager.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: gamestate manager
*/

#include "pch.h"
#include "Core/Window.h"
#include "Scenes/AllScenes.h"

PonkoEnv::GameStateManager& PonkoEnv::GameStateManager::Get()
{
	static GameStateManager s_Instance;
	return s_Instance;
}

void PonkoEnv::GameStateManager::Init()
{
	// Init Scene
	GSM_STATES StartScene			= SCENE_MAINMENU;
	GameStateManager::SetCurrent()  = GameStateManager::SetPrevious()
									= GameStateManager::SetNext()
									= StartScene;

	GameStateManager::ScenePtr() = new MainMenu;


}

void PonkoEnv::GameStateManager::Update()
{
	// game loop here
	while (GameStateManager::GetCurrent() != GSM_QUIT)
	{
		if (GameStateManager::GetCurrent() != GSM_RESTART)
		{
			GameStateManager::ScenePtr()->Load();
		}
		else
		{
			GameStateManager::SetCurrent() = GameStateManager::GetPrevious();
			GameStateManager::SetNext() = GameStateManager::GetPrevious();
		}

		GameStateManager::ScenePtr()->Init();

		while (GameStateManager::GetNext() == GameStateManager::GetCurrent())
		{
			PonkoEnv::FPSController::Get().Start(); // Start of FPS Controller

			// Input
			SDL_PollEvent(PonkoEnv::InputHandler::Get().GetSDLEvent());

			if (PonkoEnv::InputHandler::Get().GetSDLEvent()->type == SDL_QUIT)
				GameStateManager::Quit();

			// Scene Loop

			// Need to figure out why i needed to swap render and update
			// as the common sense ver makes render call first and update 2nd leading to weird stuff
			GameStateManager::ScenePtr()->Render();
			GameStateManager::ScenePtr()->Update();
			EntityManager::Get().CleanUp();

			PonkoEnv::FPSController::Get().End(); // End of FPS Controller

		}

		GameStateManager::ScenePtr()->Free();
		if (GameStateManager::GetNext() != GSM_RESTART)
		{
			GameStateManager::ScenePtr()->Unload();
		}

		GameStateManager::SetPrevious() = GameStateManager::GetCurrent();
		GameStateManager::SetCurrent() = GameStateManager::GetNext();
	}
}

void PonkoEnv::GameStateManager::Terminate()
{
	delete GameStateManager::ScenePtr();
}

void PonkoEnv::GameStateManager::SetNextScene(GSM_STATES _state) // this is horrible i think?
{
	delete GameStateManager::ScenePtr(); // dis line
	switch (_state)
	{
	case SCENE_SPLASHSCREEN:
		GameStateManager::ScenePtr() = new SplashScreenScene;
		SetCurrent() = SCENE_SPLASHSCREEN;
		break;
	case SCENE_TEST:
		GameStateManager::ScenePtr() = new TestScene;
		SetCurrent() = SCENE_TEST;
		break;
	case SCENE_MAINMENU:
		GameStateManager::ScenePtr() = new MainMenu;
		SetCurrent() = SCENE_MAINMENU;
		break;
	case SCENE_GAMEPLAY:
		GameStateManager::ScenePtr() = new Gameplay;
		SetCurrent() = SCENE_GAMEPLAY;
		break;
	default:
		break;
	}
}

void PonkoEnv::GameStateManager::Quit() // this is horrible
{
	SetNext() = GSM_QUIT;
}
