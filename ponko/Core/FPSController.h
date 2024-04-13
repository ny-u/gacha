/**
* @file:	FPSController.h
* @author:	weijie
* @date:	13 Apr 2024
* @breif:	FPS Controller via SDL
*/

#ifndef FPSCONTROLLER_H
#define FPSCONTROLLER_H

#include "SDL.h"

namespace PonkoEnv
{
	class FPSController
	{
	public:
		FPSController(FPSController const&) = delete; // remove copy constructor
		FPSController& operator=(FPSController const&) = delete; // remove assignment operator

		static FPSController& Get();
		void Start();
		void End();

	private:
		FPSController() {};

		unsigned m_fps{ PK_FPS_CAP };
		unsigned m_frameDelay{ PK_FPS_DELAY_PERIOD / m_fps};

		size_t m_frameStart{};
		int m_frameTime{};
	};
}

#endif // !FPSCONTROLLER_H
