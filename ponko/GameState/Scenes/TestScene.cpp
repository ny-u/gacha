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
	SDL_Renderer* render = PonkoEnv::PK_Window::Get().GetSDLRender();

	SDL_RenderClear(render);
	SDL_SetRenderDrawColor(render, 155, 55, 55, 255);
	SDL_RenderPresent(render);
}

void PonkoEnv::TestScene::Free()
{

}

void PonkoEnv::TestScene::Unload()
{

}