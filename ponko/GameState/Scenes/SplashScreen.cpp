/**
* @file: SplashScreen.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: splash screen to check screen transition
*/

#include "pch.h"
#include "AllScenes.h"
Entity& Player{ EntityManager::Get().addEntity()};
int counter{};

void PonkoEnv::SplashScreenScene::Load()
{
	Player.addComponent<TransformComp>();
	Player.getComponent<TransformComp>().GetPos().x = 100;
	Vec3<float> test {52, 52, 0};
	Player.addComponent<RenderComp>("assets/test.png", test);
}

void PonkoEnv::SplashScreenScene::Init()
{

}

void PonkoEnv::SplashScreenScene::Update()
{
	counter++;
	Player.getComponent<TransformComp>().GetPos().x++;
	SDL_Event event = *PonkoEnv::InputHandler::Get().GetSDLEvent();
	if (event.type)
	{
		//GameStateManager::Quit();
	}
}

void PonkoEnv::SplashScreenScene::Render()
{
	SDL_Renderer* render = PonkoEnv::PK_Window::Get().GetSDLRender();

	SDL_RenderClear(render); // Start
	SDL_SetRenderDrawColor(render, 55, 55, 55, 255);
	TextureManager::Get().SimpleDraw(Player.getComponent<RenderComp>().GetTex(), Player.getComponent<TransformComp>().GetPos(), Player.getComponent<RenderComp>().GetWidHeight());
	SDL_RenderPresent(render); // End
}

void PonkoEnv::SplashScreenScene::Free()
{

}

void PonkoEnv::SplashScreenScene::Unload()
{

}