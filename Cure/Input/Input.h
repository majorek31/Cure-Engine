#pragma once
#include "../Macros.h"
#include "InputTypes.h"
#include "../Utils/Math.h"
#include <iostream>
#include <SDL.h>

namespace Cure {
	class CURE_API Input
	{
	public:
		void Update(SDL_Event& event);

		Vec2 GetMousePos();
		bool IsMousePressed(MouseButton button);
		bool IsKeyDown(ScanCode key);
		static Input& Get();
	private:
		static Input* s_Instance;
		Input();
		Input(Input&) = delete;
		Input(const Input&) = delete;
		uint8_t* m_KBState;
		bool m_MouseState[10];
	};
}

