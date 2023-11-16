#pragma once
#include <SDL.h>
#include "../Asset.h"
namespace Cure {
	class SpriteAsset : Asset
	{
	public:
		size_t GetType();

	private:
		SDL_Texture* m_Texture;
	};
}