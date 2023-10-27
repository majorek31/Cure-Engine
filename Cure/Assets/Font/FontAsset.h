#pragma once
#include <SDL_ttf.h>
#include <string>
#include "../Asset.h"

namespace Cure {
	class CURE_API FontAsset : public Asset
	{
	public:
		FontAsset(const std::string& path, int size);
		~FontAsset();
		size_t GetType() override;
		TTF_Font* GetNativeFont();
		int GetSize();
	private:
		int m_Size;
	};
}

