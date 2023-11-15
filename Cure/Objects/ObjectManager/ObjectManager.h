#pragma once
#include <vector>
#include <algorithm>
#include "../Object.h"
#include "../../Macros.h"
#include "../../Components/BuildIn/Tag/TagComponent.h"
namespace Cure {
	class Object;
	class TagComponent;
	class CURE_API ObjectManager
	{
	public:
		ObjectManager();
		~ObjectManager();
		void RegisterObject(Object* obj);
		void DestroyObject(Object* obj);
		int GetObjectCount();
		template<typename T>
		std::vector<T*> GetObjectsByTag(const std::string& tag) {
			std::vector<T*> list;
			for (const auto obj : m_Objects) {
				if (obj->GetComponent<TagComponent>()->GetTag() == tag) {
					list.push_back(dynamic_cast<T*>(obj));
				}
			}
			return list;
		}
		template<typename T>
		T* GetObjectByTag(const std::string& tag) {
			auto list = GetObjectsByTag<T>(tag);
			return list[0];
		}
	private:
		void Start();
		void Update();
		void Render();
		friend class Scene;
		std::vector<Object*> m_Objects;
	};
}