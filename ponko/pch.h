#pragma once

// STD Lib
#include <iostream>
#include <string>

// SDL2
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

// Math
#include "Math/Vec3.h"

// Core
#include "Core/Window.h"


/*
	SDL_Window* window = PonkoEnv::PK_Window::Get().GetSDLWindow();
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

	SDL_RenderClear(render);

	SDL_RenderPresent(render);

	SDL_Delay(900);

	GameStateManager::SetNext() = GSM_QUIT;
*/