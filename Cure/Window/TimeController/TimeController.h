#pragma once
#include <iostream>
#include <chrono>

namespace Cure {
	class TimeController
	{
	public:
		TimeController(int targetFrameRate);
		void FrameStart();
		void FrameEnd();
		int GetFPS();
	private:
		std::chrono::high_resolution_clock::time_point m_Start, m_End;
		std::chrono::milliseconds m_Delta;
		int m_TargetFPS;
		int m_LastFPS;
		friend class Application;
	};
}