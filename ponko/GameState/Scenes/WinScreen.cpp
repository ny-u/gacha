/**
* @file: WinScreen.cpp
* @author: weijie
* @date: 14 apr 2024
* @brief: win screen
*/

#include "pch.h"
#include "AllScenes.h"
namespace
{
	Entity& BG{ EntityManager::Get().addEntity() };
}
void PonkoEnv::WinScreen::Load()
{
	BG.addComponent<TransformComp>(Vec3<float>(PK_WINDOW_WIDTH / 2, PK_WINDOW_HEIGHT / 2, 0));
	BG.addComponent<RenderComp>("assets/win.png", Vec3<float>(PK_WINDOW_WIDTH, PK_WINDOW_HEIGHT, 0));
}

void PonkoEnv::WinScreen::Init()
{

}

void PonkoEnv::WinScreen::Update()
{

	if (PonkoEnv::InputHandler::Get().IsMouseButtonTriggered(SDL_BUTTON_LEFT))
		GameStateManager::SetNextScene(SCENE_MAINMENU);
	
}

void PonkoEnv::WinScreen::Render()
{
	SDL_Renderer* render = PonkoEnv::PK_Window::Get().GetSDLRender();

	SDL_RenderClear(render);
	SDL_SetRenderDrawColor(render, 55, 55, 55, 255);

	TextureManager::Get().SimpleDraw(BG);

	SDL_RenderPresent(render);
}

void PonkoEnv::WinScreen::Free()
{

}

void PonkoEnv::WinScreen::Unload()
{

}