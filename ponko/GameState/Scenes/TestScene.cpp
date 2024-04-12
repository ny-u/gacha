/**
* @file: TestScene.cpp
* @author: weijie
* @date: 25 feb 2024
* @brief: testing GSM
*/

#include "pch.h"
#include "AllScenes.h"

void PonkoEnv::TestScene::Load()
{

}

void PonkoEnv::TestScene::Init()
{

}

void PonkoEnv::TestScene::Update()
{

}

void PonkoEnv::TestScene::Render()
{
	//GameStateManager::SetNextScene(SCENE_SPLASHSCREEN);
	/*
	SDL_Window* window = PonkoEnv::PK_Window::Get().GetSDLWindow();
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

	SDL_RenderClear(render);

	SDL_RenderPresent(render);

	SDL_Delay(900);
	*/

}

void PonkoEnv::TestScene::Free()
{

}

void PonkoEnv::TestScene::Unload()
{

}