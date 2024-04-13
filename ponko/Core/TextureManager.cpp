/**
* @file:	TexutreManager.cpp
* @author:	weijie
* @date:	13 Apr 2024
* @breif:	Loading textures via SDL
*/

#include "pch.h"
#include "TextureManager.h"

PonkoEnv::TextureManager& PonkoEnv::TextureManager::Get()
{
	static TextureManager s_Instance;
	return s_Instance;
}

SDL_Texture* PonkoEnv::TextureManager::LoadTexture(const char* _fileName, SDL_Renderer* _rend)
{
	SDL_Surface* tmpSurface = IMG_Load(_fileName);
	SDL_Texture* tmpTex = SDL_CreateTextureFromSurface(_rend, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tmpTex;
}