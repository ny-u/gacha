/**
* @filename:	Gameplay.cpp
* @author:		weijie
* @date:		14 Apr 2024
* @breif:		Gameplay scene
*/

#include "pch.h"
#include "AllScenes.h"

namespace
{
	Entity& BG		{ EntityManager::Get().addEntity() };
	Entity& Stick	{ EntityManager::Get().addEntity() };
}

void PonkoEnv::Gameplay::Load()
{
	BG.addComponent<TransformComp>(Vec3<float>(PK_WINDOW_WIDTH / 2, PK_WINDOW_HEIGHT / 2, 0));
	BG.addComponent<RenderComp>("assets/Gacha.png", Vec3<float>(PK_WINDOW_WIDTH, PK_WINDOW_HEIGHT, 0));

	MakeButton(Stick, Vec3<float>(475, 310, 0), Vec3<float>(50, 150, 0), "assets/cube.png");
}

void PonkoEnv::Gameplay::Init()
{
}

void PonkoEnv::Gameplay::Update()
{
	if (PonkoEnv::InputHandler::Get().IsKeyTriggered(SDLK_ESCAPE))
		GameStateManager::SetNextScene(SCENE_MAINMENU);

	if (Stick.getComponent<ColliderComp>().AABB_Point(PonkoEnv::InputHandler::Get().WindowCursor()) && PonkoEnv::InputHandler::Get().IsMouseButtonTriggered(SDL_BUTTON_LEFT))
	{
		// Gacha
		printf("Gacah\n");
	}
}

void PonkoEnv::Gameplay::Render()
{
	SDL_Renderer* render = PonkoEnv::PK_Window::Get().GetSDLRender();

	SDL_RenderClear(render);
	SDL_SetRenderDrawColor(render, 55, 55, 55, 255);

	TextureManager::Get().SimpleDraw(BG);
	TextureManager::Get().SimpleDraw(Stick);
	
	SDL_RenderPresent(render);
}

void PonkoEnv::Gameplay::Free()
{

}

void PonkoEnv::Gameplay::Unload()
{

}