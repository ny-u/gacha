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

bool PonkoEnv::InputHandler::IsKeyTriggered(SDL_Keycode _key)
{
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    SDL_Scancode scancode = SDL_GetScancodeFromKey(_key);
    return keyboardState[scancode] && m_event.type == SDL_KEYDOWN;
}

bool PonkoEnv::InputHandler::IsKeyOnHold(SDL_Keycode _key)
{
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    SDL_Scancode scancode = SDL_GetScancodeFromKey(_key);
    return keyboardState[scancode];
}

bool PonkoEnv::InputHandler::IsKeyReleased(SDL_Keycode _key)
{
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    SDL_Scancode scancode = SDL_GetScancodeFromKey(_key);
    return !keyboardState[scancode] && m_event.type == SDL_KEYUP;
}

bool PonkoEnv::InputHandler::IsMouseButtonTriggered(Uint8 button)
{
    return m_event.type == SDL_MOUSEBUTTONDOWN && m_event.button.button == button;
}

bool PonkoEnv::InputHandler::IsMouseButtonReleased(Uint8 button)
{
    return m_event.type == SDL_MOUSEBUTTONUP && m_event.button.button == button;
}

bool PonkoEnv::InputHandler::IsMouseButtonOnHold(Uint8 button)
{
    return m_event.type == SDL_MOUSEBUTTONDOWN && m_event.button.button == button;
}