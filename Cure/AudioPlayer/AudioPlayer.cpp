#include "AudioPlayer.h"
namespace Cure {
	Cure::AudioPlayer* AudioPlayer::s_Instance = nullptr;
	AudioPlayer& AudioPlayer::Get()
	{
		if (!s_Instance)
			s_Instance = new AudioPlayer;
		return *s_Instance;
	}

}