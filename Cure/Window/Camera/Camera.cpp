#include "Camera.h"
#include "../../Objects/Object.h"
#include "../../Components/BuildIn/Position/TransformComponent.h"

namespace Cure {

	Camera::Camera(Vec2 pos, float fov)
		: Object("Camera")
	{
		TransformComponent* transform = AddComponent<TransformComponent>();
		transform->m_Position = pos;
	}
	Camera::~Camera()
	{

	}
	Vec2 Camera::CalculateRelativePosition(Vec2 pos)
	{
		CURE_ASSERT(this, "Camera was null in current context");
		Vec2 outcome;
		TransformComponent* cameraTransform = GetComponent<TransformComponent>();
		outcome = pos - cameraTransform->m_Position;

		return outcome;
	}
}