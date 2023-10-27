#pragma once
#include <vector>
#include <algorithm>
#include "../Object.h"
#include "../../Macros.h"

namespace Cure {
	class Object;
	class CURE_API ObjectManager
	{
	public:
		~ObjectManager();
		void RegisterObject(Object* obj);
		void DestroyObject(Object* obj);
	private:
		void Start();
		void Update();
		void Render();
		friend class Scene;
		std::vector<Object*> m_Objects;
	};
}