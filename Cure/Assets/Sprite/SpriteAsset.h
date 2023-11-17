#pragma once
#include <SDL.h>
#include "../Asset.h"
#include "../../Utils/Math.h"
namespace Cure {
	class CURE_API SpriteAsset : public Asset
	{
	public:
		SpriteAsset(const std::string& path);
		~SpriteAsset();
		Vec2 GetSize();
		SDL_Surface* GetSurface();
		size_t GetType() override;
	private:
		Vec2 m_Size;
	};
}