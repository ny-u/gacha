/**
* @file: SplashScreen.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: splash screen to check screen transition
*/

#include "pch.h"
#include "AllScenes.h"

SDL_Texture* testTex;
SDL_Rect srcRect, dstRect;
SDL_Renderer* render;

int counter{};

void PonkoEnv::SplashScreenScene::Load()
{
	render = SDL_CreateRenderer(PonkoEnv::PK_Window::Get().GetSDLWindow(), -1, 0);

	testTex = PonkoEnv::TextureManager::Get().LoadTexture("assets/test.png", render);
}

void PonkoEnv::SplashScreenScene::Init()
{

}

void PonkoEnv::SplashScreenScene::Update()
{
	counter++;
	dstRect.h = 52;
	dstRect.w = 52;


	dstRect.x = counter%800;
	

	SDL_Event event = *PonkoEnv::InputHandler::Get().GetSDLEvent();
	if (event.type)
	{
		//GameStateManager::Quit();
	}
}

void PonkoEnv::SplashScreenScene::Render()
{
	SDL_RenderClear(render); // Start
	SDL_SetRenderDrawColor(render, 55, 55, 55, 255);
	SDL_RenderCopy(render, testTex, NULL, &dstRect);
	SDL_RenderPresent(render); // End
}

void PonkoEnv::SplashScreenScene::Free()
{

}

void PonkoEnv::SplashScreenScene::Unload()
{

}