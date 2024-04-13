/**
* @file:	TexutreManager.cpp
* @author:	weijie
* @date:	13 Apr 2024
* @breif:	Loading textures via SDL
*/

#include "pch.h"
#include "TextureManager.h"
#include "ECS/Components/allComps.h" // For TransComp and RenderComp

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
	int drawX = static_cast<int>(_pos.x - _dime.x / 4); 
	int drawY = static_cast<int>(_pos.y - _dime.y / 4); 

	SDL_Rect dstRect	= { drawX, drawY, static_cast<int>(_dime.x / 2), static_cast<int>(_dime.y / 2) };
	SDL_Renderer* rend	= PonkoEnv::PK_Window::Get().GetSDLRender();

	SDL_RenderCopy(rend, _tex, NULL, &dstRect);
}


void PonkoEnv::TextureManager::SimpleDraw(Entity& _entity)
{
	TransformComp trans = _entity.getComponent<TransformComp>();
	RenderComp rend		= _entity.getComponent<RenderComp>();

	SimpleDraw(_entity.getComponent<RenderComp>().m_texture, _entity.getComponent<TransformComp>().m_pos, _entity.getComponent<RenderComp>().m_widheight);
}