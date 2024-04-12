/**
* @file:	InputHandler.cpp
* @author:	weijie
* @date:	12 Apr 2024
* @brief:	handle events
*/

#include "pch.h"
#include "InputHandler.h"

PonkoEnv::InputHandler& PonkoEnv::InputHandler::Get()
{
	static InputHandler s_Instance;
	return s_Instance;
}

SDL_Event* PonkoEnv::InputHandler::GetSDLEvent()
{
	return &m_event;
}

