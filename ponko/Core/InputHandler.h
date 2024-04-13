/**
* @file:	InputHandler.h
* @author:	weijie
* @date:	12 Apr 2024
* @breif:	Handle SDL2 key inputs
*/

#ifndef PK_INPUTHANDLER_H
#define PK_INPUTHANDLER_H

#include <Math/Vec3.h>

namespace PonkoEnv
{
	class InputHandler // Refresher on Singeton Classes
	{
	public:
		InputHandler(InputHandler const&) = delete;
		InputHandler& operator=(InputHandler const&) = delete;

		static InputHandler& Get();
		SDL_Event* GetSDLEvent();

		// Check Keyboard Input
		bool IsKeyTriggered(SDL_Keycode _key);
		bool IsKeyOnHold(SDL_Keycode _key);
		bool IsKeyReleased(SDL_Keycode _key);

		// Check Mouse Input
		bool IsMouseButtonTriggered(Uint8 button);
		bool IsMouseButtonReleased(Uint8 button);
		bool IsMouseButtonOnHold(Uint8 button);

		// Check Cursor Pos
		Vec3<float> WindowCursor();
		Vec3<float>	GlobalCursor();
	
		// Trying out Conversion Operators
		operator SDL_Event*() { return &m_event; } // Probably unsafe but kool


	private:
		InputHandler() {};

		SDL_Event m_event;
	};
}
#endif


