/**
* @file:	TextureManager.h
* @author:	weijie
* @date:	13 Apr 2024
* @breif:	texture manager via SDL
*/

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
namespace PonkoEnv
{
	class TextureManager
	{
	public:
		TextureManager(TextureManager const&) = delete;
		TextureManager& operator=(TextureManager const&) = delete;

		static TextureManager& Get();
		SDL_Texture* LoadTexture(const char* _fileName);
		static void Draw(SDL_Texture* _tex, SDL_Rect _srcRect, SDL_Rect _dstRect);
		void SimpleDraw(SDL_Texture* _tex, Vec3<float> _pos, Vec3<float> _dime);

	private:
		TextureManager() {};

	};
}
#endif // !TEXTUREMANAGER_H



