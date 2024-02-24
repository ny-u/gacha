/**
* @file: Window.h
* @author: weijie
* @date: 25 feb 2024
* @brief: window wrapper header file
*/

#include "SDL.h"

namespace PonkoEnv
{
	class PK_Window
	{
	public:
		PK_Window(PK_Window const&) = delete;
		
		// Getters 
		static PK_Window& GetInstance();
		SDL_Window* GetSDLWindow();

		// helpers
		void ConstructWindow(const char* _title,
								int const& _width, int const& _height);

	private:
		PK_Window(){};

		const char* m_windowTitle{};
		int m_windowWidth{};
		int	m_windowHeight{};
		bool m_fullscreen{};

		SDL_Window* sdl_Window;

		static PK_Window s_Instance;
	};

}