#pragma once
#include <unordered_map>
#include <string>
#include "../Scene.h"
#include "../../Macros.h"

namespace Cure {
	class Scene;
	class CURE_API SceneManager
	{
	public:
		SceneManager();
		~SceneManager();
		void LoadScene(Scene* scene);
		Scene& GetCurrentScene();

		void Start();
		void Update();
		void Render();
	private:
		Scene* m_CurrentScene;
		std::unordered_map<std::string, Scene*> m_Scenes;
	};
}
