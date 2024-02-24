/**
* @file: PonkoEngine.h
* @author: weijie
* @date: 24 feb 2024
* @brief: starting point of the game
*/

#ifndef PK_PONKOENGINE_H
#define PK_PONKOENGINE_H

namespace PonkoEnv
{
	/**
	* @brief: the starting point of the game/application
	*/
	class PonkoEngine
	{
	public:
		static void Init();
		static void Update();
		static void Terminate();
	private:
	};
}


#endif // !PK_PONKOENGINE_H

