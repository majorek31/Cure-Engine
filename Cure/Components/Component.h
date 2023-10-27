#pragma once
#include "../Macros.h"

namespace Cure {
	class Object;
	class CURE_API Component
	{
	public:
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		Cure::Object* GetOwner();
	private:
		void SetOwner(Cure::Object* owner);
		Cure::Object* m_Owner = nullptr;
		friend class Cure::Object;
	};
}