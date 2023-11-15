#include "Application.h"
#include "ApplicationParameters.h"
#include "../Utils/DebugTimer.h"
#include "../Assets/AssetManager/AssetManager.h"
#include <string>

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

namespace Cure {
	Cure::Application* Application::s_Instance;

	Application* CreateApp(Cure::ApplicationParameters& params)
	{
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();

		Application::s_Instance = new Application(params);
		return Application::s_Instance;
	}

	Application::Application(Cure::ApplicationParameters& params)
		: m_Params(params), m_IsRunning(false)
	{
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "3");
		m_Window = new Window(params.wndParams);

		m_SceneManager = new SceneManager();

		m_TimeController = new TimeController(params.frameRate);
		
		m_Window->SetCamera(new Camera({-20, 0}, 90));
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
	const double Application::GetDeltaTime() const
	{
		auto delta = std::chrono::duration<float>(m_TimeController->m_Delta.count());
		return delta.count() / 1000.0;
	}
	uint64_t Application::GetTicks()
	{
		return SDL_GetTicks64();
	}
	void Application::Shutdown()
	{
		m_IsRunning = false;
	}
	void Application::Run()
	{
		m_IsRunning = true;
		while (m_IsRunning) {
			m_TimeController->FrameStart();
			m_Window->HandleEvents();

			m_SceneManager->Update();

			m_Window->Clear(Cure::COLOR_BLACK);
			m_SceneManager->Render();
			m_Window->RenderPresent();
			m_TimeController->FrameEnd();
		}
	}
}