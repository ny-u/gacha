/**
* @file:	FPSController.cpp
* @author:	weijie
* @date:	13 Apr 2024
* @breif:	fps controller
*/
#include "pch.h"
#include "FPSController.h"

PonkoEnv::FPSController& PonkoEnv::FPSController::Get()
{
	static FPSController s_Instance;
	return s_Instance;
}

void PonkoEnv::FPSController::Start()
{
	frameStart = SDL_GetTicks64();
}

void PonkoEnv::FPSController::End()
{
	frameTime = SDL_GetTicks64() - frameStart;
	if (frameDelay > frameTime)
		SDL_Delay(frameDelay - frameTime);
}

