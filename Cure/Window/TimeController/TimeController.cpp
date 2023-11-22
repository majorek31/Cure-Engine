#include "TimeController.h"
#include <SDL.h>
#include <iostream>
#include <thread>

namespace Cure {

	TimeController::TimeController(int targetFrameRate)
		: m_TargetFPS(targetFrameRate),
		  m_FrameCount(0)
	{}

	void TimeController::FrameStart()
	{
		m_FrameCount++;
		m_Start = std::chrono::high_resolution_clock::now();
	}

	void TimeController::FrameEnd()
	{
		m_End = std::chrono::high_resolution_clock::now();
		m_Delta = std::chrono::duration_cast<std::chrono::milliseconds>(m_End - m_Start);

		if (m_Delta.count() < 1000.0 / m_TargetFPS) {
			auto sleepTime = std::chrono::milliseconds(static_cast<long long>(1000.0 / m_TargetFPS) - m_Delta.count());
			std::this_thread::sleep_for(sleepTime);
			m_Delta += sleepTime;
		}
	}

	int TimeController::GetFPS()
	{
		return static_cast<int>(1000.0 / m_Delta.count());
	}
	uint64_t TimeController::GetFrameCount()
	{
		return m_FrameCount;
	}

}