#include "Input.h"
#include "../Window/Camera/Camera.h"
#include "../Application/Application.h"
#include "../Components/BuildIn/Position/TransformComponent.h"

namespace Cure {

	Cure::Input* Input::s_Instance = nullptr;
	void Input::ClearInputs() {
		m_MouseState.clear();
		m_KeyboardState.clear();
	}
	void Input::Update(SDL_Event& event)
	{
		switch (event.type) {
		case SDL_KEYDOWN:
			m_KeyboardState.emplace((ScanCode)event.key.keysym.scancode, (bool)event.key.repeat);
			break;

		case SDL_MOUSEBUTTONDOWN:
			m_MouseState.emplace((MouseButton)((int)event.button.button - 1), true);
			break;
		}
	}

	Vec2 Input::GetMousePos() const
	{
		Vec2 pos{ 0 };
		int x, y;
		SDL_GetMouseState(&x, &y);
		pos.x = x;
		pos.y = y;
		Camera* cam = Application::Get().GetWindow().GetCamera();
		TransformComponent* transform = cam->GetComponent<TransformComponent>();
		Vec2 out = transform->m_Position + pos;
		Vec2 screenSize = Application::Get().GetWindow().GetScreenSize();
		if (out.x < 0)
			out.x = 0;
		if (out.y < 0)
			out.y = 0;
		if (out.x > screenSize.x)
			out.x = screenSize.x;
		if (out.y > screenSize.y)
			out.y = screenSize.y;
		return out;
	}

	bool Input::GetMouse(MouseButton button) const
	{
		Uint32 mouseState = SDL_GetMouseState(0, 0);
		if (mouseState & SDL_BUTTON((int)button + 1))
			return true;
		return false;
	}

	bool Input::GetMouseDown(MouseButton button) const
	{
		for (const auto& state : m_MouseState) {
			if (state.first == button)
				return true;
		}
		return false;
	}

	bool Input::GetKey(ScanCode key) const
	{
		uint8_t* kb = (uint8_t*)SDL_GetKeyboardState(0);
		return kb[(int)key];
	}

	bool Input::GetKeyDown(ScanCode key) const
	{
		for (const auto& state : m_KeyboardState) {
			if (state.first == key)
				return true;
		}
		return false;
	}

	Cure::Input& Input::Get()
	{
		if (!s_Instance)
			s_Instance = new Cure::Input();
		return *s_Instance;
	}

	Input::Input() {}
}