#include "Input.h"

namespace Cure {

	Cure::Input* Input::s_Instance = nullptr;

	void Input::Update(SDL_Event& event)
	{
		if (event.type == SDL_EventType::SDL_MOUSEBUTTONDOWN) {
			m_MouseState[event.button.button - 1] = true;
		}
		if (event.type == SDL_EventType::SDL_MOUSEBUTTONUP) {
			m_MouseState[event.button.button - 1] = false;
		}
		m_KBState = (uint8_t*)SDL_GetKeyboardState(0);
	}

	Vec2 Input::GetMousePos()
	{
		Vec2 pos{ 0 };
		int x, y;
		SDL_GetMouseState(&x, &y);
		pos.x = x;
		pos.y = y;
		return pos;
	}

	bool Input::IsMousePressed(MouseButton button)
	{
		return m_MouseState[(int)button];
	}

	bool Input::IsKeyDown(ScanCode key)
	{
		return m_KBState[(int)(key)];
	}

	Cure::Input& Input::Get()
	{
		if (!s_Instance)
			s_Instance = new Cure::Input();
		return *s_Instance;
	}

	Input::Input() {}
}