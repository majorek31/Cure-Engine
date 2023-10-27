#pragma once
#include "../Objects/ObjectManager/ObjectManager.h"
#include "../Macros.h"

namespace Cure {	
	class ObjectManager;
	class CURE_API Scene {
	public:
		Scene();
		~Scene();
		ObjectManager& GetObjectManager();
	private:
		void Start();
		void Update();
		void Render();
		ObjectManager* m_ObjectManager;
		friend class Application;
		friend class SceneManager;
	};
}