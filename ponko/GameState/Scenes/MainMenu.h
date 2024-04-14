/**
* @filename:	MainMenu.h
* @author:		weijie
* @date:		14 Apr 2024
* @breif:		Main Menu scene
*/

#ifndef MAINMENU_H
#define MAINMENU_H

#include "BaseScene.h"

namespace PonkoEnv
{
	class MainMenu : public BaseScene
	{
		void Load() override;
		void Init() override;
		void Update() override;
		void Render() override;
		void Free() override;
		void Unload() override;
	};
}
#endif // !MAINMENU_H
