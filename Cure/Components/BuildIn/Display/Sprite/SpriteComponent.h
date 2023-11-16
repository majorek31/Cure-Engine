#pragma once
#include "../../../Component.h"
#include "../../Position/TransformComponent.h"

namespace Cure {
	class SpriteComponent : Component
	{
	public:
		void Start();
		void Update();
		void Render();
	private:
		TransformComponent* m_ObjectTransform;
	};
}