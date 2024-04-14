/**
* @filename:	Gameplay.h
* @author:		weijie
* @date:		14 Apr 2024
* @breif:		Gameplay scene
*/

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "BaseScene.h"

namespace PonkoEnv
{
	class Gameplay : public BaseScene
	{
		void Load() override;
		void Init() override;
		void Update() override;
		void Render() override;
		void Free() override;
		void Unload() override;
	};
}
#endif // !GAMEPLAY_H
