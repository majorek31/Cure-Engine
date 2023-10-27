#pragma once
#include <iostream>

namespace Cure {
	class TimeController
	{
	public:
		TimeController(int targetFrameRate);
		void FrameStart();
		void FrameEnd();
		int GetFPS();
	private:
		uint64_t m_Start, m_End;
		float m_Delta;
		int m_TargetFPS;
		int m_LastFPS;
		friend class Application;
	};
}