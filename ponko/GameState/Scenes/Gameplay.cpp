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
	TTF_Font* font	{};
	GachaSlot gs	{};
	GachaPrize prize{};
}

void PonkoEnv::Gameplay::Load()
{
	BG.addComponent<TransformComp>(Vec3<float>(PK_WINDOW_WIDTH / 2, PK_WINDOW_HEIGHT / 2, 0));
	BG.addComponent<RenderComp>("assets/Gacha.png", Vec3<float>(PK_WINDOW_WIDTH, PK_WINDOW_HEIGHT, 0));

	MakeButton(Stick, Vec3<float>(475, 310, 0), Vec3<float>(50, 150, 0), "assets/cube.png");

	font = TTF_OpenFont("assets/PressStart2P-Regular.ttf", 48);

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
		prize = gs.Pull();
		gs.counter++;
	}

	if (PonkoEnv::InputHandler::Get().IsKeyTriggered(SDLK_w))
	{
		prize = gs.Pull();
		gs.counter++;
	}

	if (prize == GachaPrize::RED_PIXEL)
	{
		GameStateManager::SetNextScene(SCENE_WINSCREEN);
	}

}

void PonkoEnv::Gameplay::Render()
{
	SDL_Renderer* render = PonkoEnv::PK_Window::Get().GetSDLRender();

	SDL_RenderClear(render);
	SDL_SetRenderDrawColor(render, 55, 55, 55, 255);

	TextureManager::Get().SimpleDraw(BG);
	TextureManager::Get().SimpleDraw(Stick);

	PonkoEnv::TextureManager::Get().TextDraw("Num of Pulls:", font, PK_COLOR_RED, Vec3<float>(160, 55, 0), Vec3<float>(300, 55, 0));
	PonkoEnv::TextureManager::Get().TextDraw(std::to_string(gs.counter).c_str(), font, PK_COLOR_RED, Vec3<float>(330, 55, 0), Vec3<float>(50, 55, 0));

	gs.DrawPrize(prize,font);
	
	SDL_RenderPresent(render);
}

void PonkoEnv::Gameplay::Free()
{
	prize = {};
	TTF_CloseFont(font);
}

void PonkoEnv::Gameplay::Unload()
{
	
}