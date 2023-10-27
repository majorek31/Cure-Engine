#pragma once
#include "../Window/WindowParameters.h"

namespace Cure {
	struct ApplicationParameters
	{
		WindowParameters wndParams;
		int frameRate = 60;
		int version = 0;
	};
}