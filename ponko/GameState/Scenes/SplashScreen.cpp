/**
* @file: SplashScreen.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: splash screen to check screen transition
*/

#include "pch.h"
#include "AllScenes.h"
Entity& Player{ EntityManager::Get().addEntity()};

void PonkoEnv::SplashScreenScene::Load()
{
	Player.addComponent<TransformComp>();
	Player.getComponent<TransformComp>().m_pos = 100;
	Vec3<float> test {52, 52, 0};
	Player.addComponent<RenderComp>("assets/test.png", test);
}

void PonkoEnv::SplashScreenScene::Init()
{

}

void PonkoEnv::SplashScreenScene::Update()
{
	// Poll SDL events
	//SDL_PollEvent(PonkoEnv::InputHandler::Get().GetSDLEvent());

	// Check if the Escape key is triggered
	if (PonkoEnv::InputHandler::Get().IsKeyReleased(SDLK_ESCAPE))
	{
		std::cout << "Escape key is triggered\n";
	}

	// Update player's position
	Player.getComponent<TransformComp>().m_pos.x++;
	
}

void PonkoEnv::SplashScreenScene::Render()
{
	SDL_Renderer* render = PonkoEnv::PK_Window::Get().GetSDLRender();

	SDL_RenderClear(render); // Start
	SDL_SetRenderDrawColor(render, 55, 55, 55, 255);
	TextureManager::Get().SimpleDraw(Player);
	SDL_RenderPresent(render); // End
}

void PonkoEnv::SplashScreenScene::Free()
{

}

void PonkoEnv::SplashScreenScene::Unload()
{

}