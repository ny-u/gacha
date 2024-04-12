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

	

	SDL_Surface* tmpSurface = IMG_Load("assets/test.png");
	SDL_Texture* testTex = SDL_CreateTextureFromSurface(render, tmpSurface);
	SDL_FreeSurface(tmpSurface);


	SDL_RenderClear(render); // Start
	SDL_SetRenderDrawColor(render, 255, 0, 255, 255);
	SDL_RenderCopy(render, testTex, NULL, NULL);
	SDL_RenderPresent(render); // End

}

void PonkoEnv::SplashScreenScene::Free()
{

}

void PonkoEnv::SplashScreenScene::Unload()
{

}