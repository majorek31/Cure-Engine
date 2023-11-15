#pragma once
#include <iostream>


#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif
#ifdef _WINDLL
#define CURE_API __declspec(dllexport)
#else
#define CURE_API __declspec(dllimport)
#endif

#define CURE_ASSERT(x, ...) \
	if (!x) { std::cerr << "\nAssertion (" << #x << ") failed at " << __FUNCTION__  << " in " __FILE__ << "\nInfo:" << __VA_ARGS__ << "\n"; __debugbreak(); }

#define CURE_UNIMPLEMENTED() \
	std::cerr << "\n\tUnimplemented function: " << __FUNCTION__  << " in " __FILE__ << "\n"; __debugbreak();