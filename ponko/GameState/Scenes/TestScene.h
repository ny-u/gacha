/**
* @file: TestScene.h
* @author: weijie
* @date: 24 feb 2024
* @brief: testing GSM
*/

#ifndef PK_TESTSCENE_H
#define PK_TESTSCENE_H
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
#endif // !PK_TESTSCENE_H
