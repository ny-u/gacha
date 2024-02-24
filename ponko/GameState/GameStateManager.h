/**
* @file: GameStateManager.h
* @author: weijie
* @date: 24 feb 2024
* @brief: gamestate manager
*/

#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H
#include "Scenes/BaseScene.h"

	namespace PonkoEnv
	{
		enum GSM_STATES : int
		{
			GSM_NULL,
			SCENE_SPLASHSCREEN,
			SCENE_TEST,
			GSM_QUIT,
			GSM_RESTART
		};

		class GameStateManager
		{
		public:
			GameStateManager(GameStateManager const&) = delete;
			GameStateManager& operator= (GameStateManager const&) = delete;

			static GameStateManager& Get();
			
			static void Init();
			static void Update();
			static void Terminate();

			static GSM_STATES GetCurrent() { return Get().I_GetCurrent(); }
			static GSM_STATES& SetCurrent() { return Get().I_SetCurrent(); }

			static GSM_STATES GetPrevious() { return Get().I_GetPrevious(); }
			static GSM_STATES& SetPrevious() { return Get().I_SetPrevious(); }

			static GSM_STATES GetNext() { return Get().I_GetNext(); }
			static GSM_STATES& SetNext() { return Get().I_SetNext(); }

			static BaseScene*& ScenePtr() { return Get().I_ScenePtr(); }

			static void SetNextScene(GSM_STATES _state);
			static void Quit();

		private:
			GameStateManager() {};
			GSM_STATES I_GetCurrent() { return m_current; }
			GSM_STATES& I_SetCurrent() { return m_current; }

			GSM_STATES I_GetPrevious() { return m_previous; }
			GSM_STATES& I_SetPrevious() { return m_previous; }

			GSM_STATES I_GetNext() { return m_next; }
			GSM_STATES& I_SetNext() { return m_next; }

			BaseScene*& I_ScenePtr() { return m_scene; }

			GSM_STATES m_current{};
			GSM_STATES m_previous{};
			GSM_STATES m_next{};

			BaseScene* m_scene;
		};

	}
#endif // !GAMESTATEMANAGER_H


