#include "SpriteAsset.h"
#include <typeinfo>
#include <SDL_image.h>
#include "../../Application/Application.h"
namespace Cure {
	SpriteAsset::SpriteAsset(const std::string& path)
	{
		SDL_Surface* surface = IMG_Load(path.c_str()); 
		CURE_ASSERT(surface, SDL_GetError());
		m_Size.x = surface->w;
		m_Size.y = surface->h;
		m_NativeAsset = Application::Get().GetWindow().CreateTextureFromSurface(surface);
		SDL_FreeSurface(surface);
	}
	SpriteAsset::~SpriteAsset()
	{
		SDL_DestroyTexture(GetTexture());
	}
	Vec2 SpriteAsset::GetSize()
	{
		return m_Size;
	}
	SDL_Texture* SpriteAsset::GetTexture()
	{
		return static_cast<SDL_Texture*>(m_NativeAsset);
	}
	size_t SpriteAsset::GetType()
	{
		return typeid(*this).hash_code();
	}
}