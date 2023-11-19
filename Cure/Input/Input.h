#pragma once
#include "../Macros.h"
#include "InputTypes.h"
#include "../Utils/Math.h"
#include <iostream>
#include <SDL.h>
#include <unordered_map>

namespace Cure {
	class CURE_API Input
	{
	public:
		void Update(SDL_Event& event);

		Vec2 GetMousePos() const;
		bool GetMouse(MouseButton button) const;
		bool GetMouseDown(MouseButton button) const;

		bool GetKey(ScanCode key) const;
		bool GetKeyDown(ScanCode key) const;
		static Input& Get();
	private:
		static Input* s_Instance;
		Input();
		Input(Input&) = delete;
		Input(const Input&) = delete;
		void ClearInputs();

		std::unordered_map<ScanCode, bool> m_KeyboardState;
		std::unordered_map<MouseButton, bool> m_MouseState;

		friend class Window;
	};
}

