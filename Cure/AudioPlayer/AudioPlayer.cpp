#include "AudioPlayer.h"
#include <SDL_mixer.h>
namespace Cure {
	Cure::AudioPlayer* AudioPlayer::s_Instance = nullptr;
	AudioPlayer::AudioPlayer() { }
	AudioPlayer& AudioPlayer::Get()
	{
		if (!s_Instance)
			s_Instance = new AudioPlayer;
		return *s_Instance;
	}

	void AudioPlayer::StopPlaying()
	{
		Mix_HaltMusic();
	}

	void AudioPlayer::Play(AudioAsset* audio, int volume)
	{
		Mix_Volume(-1, volume);
		Mix_PlayMusic(audio->GetNativeMusic(), 0);
	}

}