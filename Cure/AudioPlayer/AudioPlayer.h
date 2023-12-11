#pragma once
#include "../Assets/Audio/AudioAsset.h"
#include "../Macros.h"
namespace Cure {
	class CURE_API AudioPlayer
	{
	public:
		static AudioPlayer& Get();
		void StopPlaying();
		void Play(AudioAsset audio, int volume);
	private:
		AudioPlayer();
		AudioPlayer(const AudioPlayer&) = delete;
		AudioPlayer(AudioPlayer&) = delete;
		static AudioPlayer* s_Instance;
	};
}

