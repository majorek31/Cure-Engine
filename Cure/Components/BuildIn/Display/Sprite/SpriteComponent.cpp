#include "SpriteComponent.h"
#include "../../../../Objects/Object.h"

namespace Cure {
	void SpriteComponent::Start()
	{
		m_ObjectTransform = GetOwner()->GetComponent<TransformComponent>();
		CURE_ASSERT(m_ObjectTransform, "Object has no TransfromComponent");
	}
	void SpriteComponent::Update()
	{

	}
	void SpriteComponent::Render()
	{

	}
}
