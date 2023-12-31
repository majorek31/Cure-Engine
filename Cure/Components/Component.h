#pragma once
#include "../Macros.h"

namespace Cure {
	class Object;
	class ObjectManager;
	class CURE_API Component
	{
	public:
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		Cure::Object* GetOwner();
	private:
		void SetOwner(Cure::Object* owner);
		void Initialize();
	private:
		Cure::Object* m_Owner = nullptr;
		bool m_IsInitialized = false;
		friend class Cure::Object;
		friend class Cure::ObjectManager;
	};
}