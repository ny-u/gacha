/**
* @file: SplashScreen.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: splash screen to check screen transition
*/

#include "pch.h"
#include "AllScenes.h"

void PonkoEnv::SplashScreenScene::Load()
{

}

void PonkoEnv::SplashScreenScene::Init()
{

}

void PonkoEnv::SplashScreenScene::Update()
{

	//GameStateManager::Quit();

	SDL_Event event = *PonkoEnv::InputHandler::Get().GetSDLEvent();
	if (event.type);
}

void PonkoEnv::SplashScreenScene::Render()
{
	SDL_Renderer* render = SDL_CreateRenderer(PonkoEnv::PK_Window::Get().GetSDLWindow(), -1, 0);

	SDL_SetRenderDrawColor(render, 255, 0, 255, 255);

	SDL_RenderClear(render);

	SDL_RenderPresent(render);

}

void PonkoEnv::SplashScreenScene::Free()
{

}

void PonkoEnv::SplashScreenScene::Unload()
{

}