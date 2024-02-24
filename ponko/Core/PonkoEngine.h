/**
* @file: PonkoEngine.h
* @author: weijie
* @date: 24 feb 2024
* @brief: starting point of the game
*/

#ifndef PONKOENGINE_H
#define PONKOENGINE_H

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


#endif // !PONKOENGINE_H

