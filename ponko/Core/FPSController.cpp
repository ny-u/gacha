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
	m_frameStart = SDL_GetTicks64();
}

void PonkoEnv::FPSController::End()
{
	m_frameTime = SDL_GetTicks64() - m_frameStart;
	if (m_frameDelay > m_frameTime)
		SDL_Delay(m_frameDelay - m_frameTime);
}

