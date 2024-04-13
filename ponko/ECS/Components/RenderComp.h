/**
* @filename:	RenderComp.h
* @author:		weijie
* @date:		13 Apr 2024
* @breif:		textures component
*/

#ifndef RENDERCOMP_H
#define RENDERCOMP_H

#include "ECS/ECS.h"
#include "ECS/Components/allComps.h"
#include "SDL.h"
#include "Math/Vec3.h"
#include "Core/TextureManager.h"

struct RenderComp : public Component
{
	RenderComp() {}
	RenderComp(const char* _filePath) : RenderComp()
	{
		m_texture = PonkoEnv::TextureManager::Get().LoadTexture(_filePath);
	}

	RenderComp(const char* _filePath, Vec3<float> _widHeight) : m_widheight(_widHeight)
	{
		m_texture = PonkoEnv::TextureManager::Get().LoadTexture(_filePath);
	}

	//Vec3<float> m_pos{};
	Vec3<float>		m_widheight{};
	SDL_Texture*	m_texture;
	SDL_Rect		m_srcRect{};
	SDL_Rect		m_dstRect{};

};

#endif // !RENDERCOMP_H
