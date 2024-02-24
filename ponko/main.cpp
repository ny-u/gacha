/**
* @author: weijie
* @date: 25 feb 2024
* @brief: main 
*/

#include "pch.h"
#include "Core/PonkoEngine.h"

int main(int argc, char** argv)
{
	PonkoEnv::PonkoEngine::Init();
	PonkoEnv::PonkoEngine::Update();
	PonkoEnv::PonkoEngine::Terminate();

	return 0;
}