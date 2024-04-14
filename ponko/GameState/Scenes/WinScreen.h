/**
* @file: WinScreen.h
* @author: weijie
* @date: 14 apr 2024
* @brief: win screen
*/

#ifndef PK_WINSCREEN_H
#define PK_WINSCREEN_H
#include "BaseScene.h"
namespace PonkoEnv
{
	class WinScreen : public BaseScene
	{
		void Load() override;
		void Init() override;
		void Update() override;
		void Render() override;
		void Free() override;
		void Unload() override;
	};
}
#endif // !PK_TESTSCENE_H
