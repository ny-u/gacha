/**
* @file: BaseScene.h
* @author: weijie
* @date: 24 feb 2024
* @brief: BaseScene to be used in game state
*/

#ifndef PK_BASESCENE_H
#define PK_BASESCENE_H
	namespace PonkoEnv
	{
		class BaseScene
		{
		public:
			virtual void Load() = 0;
			virtual void Init() = 0;
			virtual void Update() = 0;
			virtual void Render() = 0;
			virtual void Free() = 0;
			virtual void Unload() = 0;
		};
	}
#endif // !PK_BASESCENE_H


