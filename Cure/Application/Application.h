#pragma once

#include "../Macros.h"
#include "ApplicationParameters.h"
#include "../Window/Window.h"
#include "../Scenes/SceneManager/SceneManager.h"
#include "../Window/TimeController/TimeController.h"

namespace Cure {
	class SceneManager;
	class Window;
	class CURE_API Application
	{
	public:
		Application(const Application&) = delete;
		Application(Application&) = delete;
		virtual ~Application();

		int GetCureVersion();
		int GetFPS();
		Window& GetWindow();
		SceneManager& GetSceneManager();
		bool IsRunning() const;
		const double GetDeltaTime() const;
		uint64_t GetTicks();

		void Shutdown();
		void Run();
	private:
		Application(Cure::ApplicationParameters& params);
		Window* m_Window;
		SceneManager* m_SceneManager;
		bool m_IsRunning;
	public: // singleton stuff below this line
		static Application& Get();
	private:
		static Application* s_Instance;
		Cure::ApplicationParameters m_Params;
		TimeController* m_TimeController;
		friend CURE_API Application* CreateApp(Cure::ApplicationParameters& params);
	};
	CURE_API Application* CreateApp(Cure::ApplicationParameters& params);
}

