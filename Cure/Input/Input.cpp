#include "Input.h"
#include "../Window/Camera/Camera.h"
#include "../Application/Application.h"
#include "../Components/BuildIn/Position/TransformComponent.h"

namespace Cure {

	Cure::Input* Input::s_Instance = nullptr;

	void Input::Update(SDL_Event& event)
	{
		if (event.type == SDL_EventType::SDL_MOUSEBUTTONDOWN) {
			m_KBState = (uint8_t*)SDL_GetKeyboardState(0);
			m_MouseState[event.button.button - 1] = true;
		}
		if (event.type == SDL_EventType::SDL_MOUSEBUTTONUP) {
			m_MouseState[event.button.button - 1] = false;
		}
		m_KBState = (uint8_t*)SDL_GetKeyboardState(0);
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

	bool Input::IsMousePressed(MouseButton button) const
	{
		return m_MouseState[(int)button];
	}

	bool Input::IsKeyPressed(ScanCode key) const
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