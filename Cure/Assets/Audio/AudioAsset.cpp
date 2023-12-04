#include "AudioAsset.h"

namespace Cure {
	AudioAsset::AudioAsset(const std::string& path, AudioType type) {
		switch (type)
		{
		case Cure::AudioType::MP3:
			CURE_UNIMPLEMENTED();
			break;
		case Cure::AudioType::WAV:
			m_NativeAsset = Mix_LoadMUS(path.c_str());
			break;
		default:
			break;
		}
		CURE_ASSERT(m_NativeAsset, "Couldn't load music asset");
	}

	AudioAsset::~AudioAsset()
	{
		Mix_FreeMusic(GetNativeMusic());
	}

	size_t AudioAsset::GetType()
	{
		return typeid(*this).hash_code();
	}

	Mix_Music* AudioAsset::GetNativeMusic()
	{
		return static_cast<Mix_Music*>(m_NativeAsset);
	}

}