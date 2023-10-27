#pragma once
#include "../../Component.h"

#include "../../../Utils/Math.h"
namespace Cure {
	class CURE_API TransformComponent : public Component
	{
	public:
		TransformComponent();
		TransformComponent(Vec2 pos);
		void Start() override;
		void Update() override;
		void Render() override;

		Vec2 m_Position;
		Vec2 m_Velocity;
		float m_Angle;
	};
}