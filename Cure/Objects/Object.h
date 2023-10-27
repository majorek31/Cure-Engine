#pragma once
#include <unordered_map>
#include <typeinfo>
#include "../Application/Application.h"
#include "../Components/Component.h"
#include "../Macros.h"

namespace Cure {
	class CURE_API Object
	{
	public:
		Object(const std::string& tag);
		Object();
		virtual ~Object();

		template<typename T, typename... TArgs>
		T* AddComponent(TArgs&... args) {
			if (HasComponent<T>())
				return GetComponent<T>();
			size_t tag = typeid(T).hash_code();
			Component* comp = reinterpret_cast<Component*>(new T(args...));
			m_Components.emplace(tag, comp);
			comp->SetOwner(this);
			return (T*)comp;
		}

		template<typename T>
		bool HasComponent() {
			return GetComponent<T>() ? true : false;
		}

		template<typename T>
		T* GetComponent() {
			for (const auto& entry : m_Components)
			{
				if (entry.first == typeid(T).hash_code())
					return (T*)entry.second;
			}
			return nullptr;
		}
	private:
		std::unordered_map<size_t, Component*> m_Components;
		friend class ObjectManager;
	};
}
