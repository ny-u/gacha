/**
* @file: SplashScreen.h
* @author: weijie
* @date: 24 feb 2024
* @brief: splash screen to check screen transition
*/

#ifndef PK_SPLASHSCREEN_H
#define PK_SPLASHSCREEN_H
#include "BaseScene.h"
namespace PonkoEnv
{
	class SplashScreenScene : public BaseScene
	{
		void Load() override;
		void Init() override;
		void Update() override;
		void Render() override;
		void Free() override;
		void Unload() override;
	};
}
#endif // !PK_SPLASHSCREEN_H
