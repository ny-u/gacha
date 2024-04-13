/**
* @file: SplashScreen.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: splash screen to check screen transition
*/

#include "pch.h"
#include "AllScenes.h"
SDL_Renderer* render;
Entity& Player{ EntityManager::Get().addEntity() };
Entity& Box{ EntityManager::Get().addEntity() };


void PonkoEnv::SplashScreenScene::Load()
{
	Player.addComponent<TransformComp>();
	Vec3<float> test {255, 255, 0};
	Player.addComponent<RenderComp>("assets/test.png", test);
	render = PonkoEnv::PK_Window::Get().GetSDLRender();

	//Box.addComponent<ColliderComp>(AABB(200,200,0));
	Box.addComponent<ColliderComp>(AABB(Vec3<float>(0, 0, 0), Vec3<float>(200, 200, 0)));

}

void PonkoEnv::SplashScreenScene::Init()
{

}

void PonkoEnv::SplashScreenScene::Update()
{
	// Check if the Escape key is triggered
	if (PonkoEnv::InputHandler::Get().IsMouseButtonTriggered(SDL_BUTTON_LEFT))
	{
		std::cout << "Mouse key is triggered\n" << PonkoEnv::InputHandler::Get().WindowCursor() << '\n';
	}
	if (PonkoEnv::InputHandler::Get().IsKeyTriggered(SDLK_w))
	{
		std::cout << "W key is triggered\n" << PonkoEnv::InputHandler::Get().WindowCursor() << '\n';
	}
	if (Box.getComponent<ColliderComp>().AABB_Point(PonkoEnv::InputHandler::Get().WindowCursor()))
	{
		std::cout << "Hey Touching Box is expensive!\n";
	}


	// Update player's position
	Player.getComponent<TransformComp>().m_pos = PonkoEnv::InputHandler::Get().WindowCursor();
	
}

void PonkoEnv::SplashScreenScene::Render()
{
	 

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