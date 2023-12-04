#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "../Asset.h"
#include "AudioFiles.h"
namespace Cure {
	class AudioAsset : public Asset
	{
		AudioAsset(const std::string& path, AudioType type);
		~AudioAsset();
		size_t GetType() override;
		Mix_Music* GetNativeMusic();
	};
}

