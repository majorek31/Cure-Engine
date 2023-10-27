#include "Application.h"
#include "ApplicationParameters.h"
#include "../Utils/DebugTimer.h"
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

namespace Cure {
	Cure::Application* Application::s_Instance;

	Application* CreateApp(Cure::ApplicationParameters& params)
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		TTF_Init();

		Application::s_Instance = new Application(params);
		return Application::s_Instance;
	}

	Application::Application(Cure::ApplicationParameters& params)
		: m_Params(params), m_IsRunning(false)
	{
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "3");
		m_Window = new Window(params.wndParams);
		CURE_ASSERT(m_Window);

		m_SceneManager = new SceneManager();
		CURE_ASSERT(m_SceneManager);

		m_TimeController = new TimeController(params.frameRate);
		CURE_ASSERT(m_TimeController);
	}

	Application::~Application()
	{
		delete m_Window;
		delete m_SceneManager;
		delete m_TimeController;
		TTF_Quit();
		SDL_Quit();
	}

	Application& Application::Get() { return *s_Instance; }

	int Application::GetCureVersion()
	{
		return m_Params.version;
	}
	int Application::GetFPS()
	{
		return m_TimeController->GetFPS();
	}
	Window& Application::GetWindow()
	{
		return *m_Window;
	}
	SceneManager& Application::GetSceneManager() {
		return *m_SceneManager;
	}
	bool Application::IsRunning() const
	{
		return m_IsRunning;
	}
	const float Application::GetDeltaTime() const
	{
		return m_TimeController->m_Delta;
	}
	void Application::Shutdown()
	{
		m_IsRunning = false;
	}
	void Application::Run()
	{
		m_SceneManager->Start();
		m_IsRunning = true;
		while (m_IsRunning) {
			m_TimeController->FrameStart();
			m_Window->HandleEvents();

			m_SceneManager->Update();

			m_SceneManager->Render();
			m_Window->RenderPresent();
			m_TimeController->FrameEnd();
		}
	}
}