/**
* @filename:	MainMenu.cpp
* @author:		weijie
* @date:		14 Apr 2024
* @breif:		Main Menu scene
*/

#include "pch.h"
#include "AllScenes.h"

namespace
{
	Entity& BG			{ EntityManager::Get().addEntity() };
	Entity& btn_Start	{ EntityManager::Get().addEntity() };
	Entity& btn_Quit	{ EntityManager::Get().addEntity() };
}

void PonkoEnv::MainMenu::Load()
{
	BG.addComponent<TransformComp>(Vec3<float>(PK_WINDOW_WIDTH /2, PK_WINDOW_HEIGHT /2, 0));
	BG.addComponent<RenderComp>("assets/Title.png", Vec3<float>(PK_WINDOW_WIDTH, PK_WINDOW_HEIGHT, 0));

	MakeButton(btn_Start, Vec3<float>(120, 310, 0), Vec3<float>(160, 32, 0), "assets/start.png");
	MakeButton(btn_Quit, Vec3<float>(120, 410, 0), Vec3<float>(160, 32, 0), "assets/quit.png");

}

void PonkoEnv::MainMenu::Init()
{

}

void PonkoEnv::MainMenu::Update()
{
	if (btn_Start.getComponent<ColliderComp>().AABB_Point(PonkoEnv::InputHandler::Get().WindowCursor()) && PonkoEnv::InputHandler::Get().IsMouseButtonTriggered(SDL_BUTTON_LEFT))
		GameStateManager::SetNextScene(SCENE_GAMEPLAY);

	if (btn_Quit.getComponent<ColliderComp>().AABB_Point(PonkoEnv::InputHandler::Get().WindowCursor()) && PonkoEnv::InputHandler::Get().IsMouseButtonTriggered(SDL_BUTTON_LEFT))
		GameStateManager::Quit();

	
}

void PonkoEnv::MainMenu::Render()
{
	SDL_Renderer* render = PonkoEnv::PK_Window::Get().GetSDLRender();

	SDL_RenderClear(render);
	SDL_SetRenderDrawColor(render, 55, 55, 55, 255);


	TextureManager::Get().SimpleDraw(BG);
	TextureManager::Get().SimpleDraw(btn_Start);
	TextureManager::Get().SimpleDraw(btn_Quit);


	SDL_RenderPresent(render);
}

void PonkoEnv::MainMenu::Free()
{
	BG.Destroy();
	btn_Start.Destroy();
	btn_Quit.Destroy();
}

void PonkoEnv::MainMenu::Unload()
{

}