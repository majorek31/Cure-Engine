#pragma once
#include "../Macros.h"
namespace Cure {
	class CURE_API AudioPlayer
	{
	public:
		AudioPlayer& Get();
	private:
		AudioPlayer();
		AudioPlayer(const AudioPlayer&) = delete;
		AudioPlayer(AudioPlayer&) = delete;
		static AudioPlayer* s_Instance;
	};
}

