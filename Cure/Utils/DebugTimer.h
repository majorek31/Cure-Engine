#pragma once
#include <chrono>
#include <iostream>

struct DebugTimer {
	std::string m_Name;
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

	DebugTimer(const std::string& n) : m_Name(n) {
		start = std::chrono::high_resolution_clock::now();
	}

	~DebugTimer() {
		end = std::chrono::high_resolution_clock::now();
		auto duration = end - start;
		std::cout << "Execution of " << m_Name << " took " << duration.count() << "ms\n";
	}
};
#ifdef _DEBUG
	#define CURE_TIME() DebugTimer(__FUNCTION__);
#else
	#define CURE_TIME() void;
#endif
