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

SDL_Texture* PonkoEnv::TextureManager::LoadTexture(const char* _fileName)
{
	SDL_Renderer* rend = PonkoEnv::PK_Window::Get().GetSDLRender();
	SDL_Surface* tmpSurface = IMG_Load(_fileName);
	SDL_Texture* tmpTex = SDL_CreateTextureFromSurface(rend, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tmpTex;
}

void PonkoEnv::TextureManager::Draw(SDL_Texture* _tex, SDL_Rect _srcRect,SDL_Rect _dstRect)
{
	SDL_Renderer* rend = PonkoEnv::PK_Window::Get().GetSDLRender();
	SDL_RenderCopy(rend,_tex,NULL,&_dstRect);
}

void PonkoEnv::TextureManager::SimpleDraw(SDL_Texture* _tex, Vec3<float> _pos, Vec3<float> _dime)
{
	SDL_Rect dstRect{};
	dstRect.x = _pos.x;
	dstRect.y = _pos.y;

	dstRect.h = _dime.x;
	dstRect.w = _dime.y;

	SDL_Renderer* rend = PonkoEnv::PK_Window::Get().GetSDLRender();
	SDL_RenderCopy(rend, _tex, NULL, &dstRect);
}

