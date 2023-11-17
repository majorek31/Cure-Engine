#include "SpriteAsset.h"
#include <typeinfo>
#include <SDL_image.h>
namespace Cure {
	SpriteAsset::SpriteAsset(const std::string& path)
	{
		SDL_Surface* surface = IMG_Load(path.c_str()); 
		CURE_ASSERT(surface, SDL_GetError());
		m_NativeAsset = static_cast<void*>(surface);
		m_Size.x = surface->w;
		m_Size.y = surface->h;
	}
	SpriteAsset::~SpriteAsset()
	{
		SDL_FreeSurface(static_cast<SDL_Surface*>(m_NativeAsset));
	}
	Vec2 SpriteAsset::GetSize()
	{
		return m_Size;
	}
	SDL_Surface* SpriteAsset::GetSurface()
	{
		return static_cast<SDL_Surface*>(m_NativeAsset);
	}
	size_t SpriteAsset::GetType()
	{
		return typeid(*this).hash_code();
	}
}