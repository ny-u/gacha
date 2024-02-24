/**
* @file: BaseScene.h
* @author: weijie
* @date: 24 feb 2024
* @brief: BaseScene to be used in game state
*/

#ifndef TESTSCENE_H
#define TESTSCENE_H
#include "BaseScene.h"
	namespace PonkoEnv
	{
		class TestScene : public BaseScene
		{
			void Load() override;
			void Init() override;
			void Update() override;
			void Render() override;
			void Free() override;
			void Unload() override;
		};
	}
#endif // !TESTSCENE_H
