/**
* @file:	InputHandler.h
* @author:	weijie
* @date:	12 Apr 2024
* @breif:	Handle SDL2 key inputs
*/

#ifndef PK_INPUTHANDLER_H
#define PK_INPUTHANDLER_H
namespace PonkoEnv
{
	class InputHandler // Refresher on Singeton Classes
	{
	public:
		InputHandler(InputHandler const&) = delete;
		InputHandler& operator=(InputHandler const&) = delete;

		static InputHandler& Get();
		SDL_Event* GetSDLEvent();

		bool IsKeyTriggered(SDL_Keycode _key);
		bool IsKeyOnHold(SDL_Keycode _key);
		bool IsKeyReleased(SDL_Keycode _key);

		// Trying out Conversion Operators
		operator SDL_Event*() { return &m_event; } // Probably unsafe but kool


	private:
		InputHandler() {};

		SDL_Event m_event;
	};
}
#endif


