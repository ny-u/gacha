#include "SDL.h"

namespace PonkoEnv
{
	class PK_Window
	{
	public:
		PK_Window(PK_Window const&) = delete;

		PK_Window(const char* title, 
				  int const& _wdith,
				  int const& _height);
	private:
		const char* m_windowTitle{};
		int m_windowWidth{};
		int	m_windowHeight{};
		bool m_fullscreen{};

		SDL_Window* sdl_Window{};
	};
}