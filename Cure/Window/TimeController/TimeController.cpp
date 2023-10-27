#include "TimeController.h"
#include <SDL.h>
#include <iostream>

namespace Cure {

	TimeController::TimeController(int targetFrameRate)
		: m_TargetFPS(targetFrameRate),
		m_Delta(0),
		m_End(0),
		m_Start(0),
		m_LastFPS(0)
	{}

	void TimeController::FrameStart()
	{
		m_Start = SDL_GetPerformanceCounter();
	}

	void TimeController::FrameEnd()
	{

		if (m_Delta <= 1000.f / m_TargetFPS)
			SDL_Delay(1000.f / m_TargetFPS - m_Delta);

		m_End = SDL_GetPerformanceCounter();
		m_Delta = (m_End - m_Start) / (float)SDL_GetPerformanceFrequency();
	}

	int TimeController::GetFPS()
	{
		return 1.f / m_Delta;
	}

}