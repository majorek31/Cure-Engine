#include "FontAsset.h"

#include <typeinfo>

namespace Cure {

	FontAsset::FontAsset(const std::string& path, int size)
		: m_Size(size)
	{		
		m_NativeAsset = TTF_OpenFont(path.c_str(), size);
		CURE_ASSERT(m_NativeAsset, SDL_GetError());
	}

	FontAsset::~FontAsset()
	{
		TTF_CloseFont(GetNativeFont());
	}

	TTF_Font* FontAsset::GetNativeFont()
	{
		return static_cast<TTF_Font*>(m_NativeAsset);
	}

	int FontAsset::GetSize()
	{
		return m_Size;
	}
	size_t FontAsset::GetType() {
		return typeid(*this).hash_code();
	}
}