#include "TransformComponent.h"
#include "../../../Application/Application.h"

namespace Cure {
	TransformComponent::TransformComponent()
		: m_Position({0, 0}),
		  m_Velocity({ 0, 0 }),
		  m_Angle(0)
	{}
	TransformComponent::TransformComponent(Vec2 pos)
		: m_Position(pos),
		  m_Velocity({ 0, 0 }),
		  m_Angle(0)
	{}
	void TransformComponent::Start()
	{

	}

	void TransformComponent::Update()
	{
		float deltaTime = Cure::Application::Get().GetDeltaTime();
		/*
				constexpr float braking = 3.2f;
		if (m_Velocity.x > 0)
			m_Velocity.x -= braking;
		if (m_Velocity.x < 0)
			m_Velocity.x += braking;

		if (m_Velocity.y < 0)
			m_Velocity.y += braking;

		if (m_Velocity.y > 0)
			m_Velocity.y -= braking;

		if (m_Velocity.x > -1.f && m_Velocity.x < 1.f)
			m_Velocity.x = 0;

		if (m_Velocity.y > -1.f && m_Velocity.y < 1.f)
			m_Velocity.y = 0;


		*/
	}
	void TransformComponent::Render() {}

}