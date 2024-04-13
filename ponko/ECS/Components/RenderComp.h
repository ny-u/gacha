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

class RenderComp : public Component
{
public:
	RenderComp()
	{
		m_dstRect.x = m_dstRect.y = 0;
		m_srcRect.w = m_srcRect.h = 32;
		m_dstRect.w = m_dstRect.h = 64;
	}
	RenderComp(const char* _filePath) : RenderComp()
	{
		m_texture = PonkoEnv::TextureManager::Get().LoadTexture(_filePath);
	}

	RenderComp(const char* _filePath, Vec3<float> _widHeight) : m_widheight(_widHeight)
	{
		m_texture = PonkoEnv::TextureManager::Get().LoadTexture(_filePath);
	}

	void Update() override
	{
		TransformComp trans = entity->getComponent<TransformComp>();
		m_dstRect.x = 0;// trans.GetPos().x;
		m_dstRect.y = 0;// trans.GetPos().y;
	}

	void Draw() override
	{
		PonkoEnv::TextureManager::Draw(m_texture, m_srcRect, m_dstRect);
	}

	SDL_Texture* GetTex()
	{
		return m_texture;
	}

	Vec3<float> GetWidHeight()
	{
		return m_widheight;
	}

private:
	//Vec3<float> m_pos{};
	Vec3<float> m_widheight{};
	SDL_Texture* m_texture;
	SDL_Rect m_srcRect{};
	SDL_Rect m_dstRect{};

};

#endif // !RENDERCOMP_H
