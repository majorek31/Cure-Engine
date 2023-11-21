#include "SpriteComponent.h"
#include "../../../../Objects/Object.h"
#include "../../../../Application/Application.h"

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
		if (!m_Sprite)
			return;
		Application::Get().GetWindow().RenderTexture(m_ObjectTransform->m_Position, m_Sprite, m_ObjectTransform->m_Angle);
	}
	void SpriteComponent::SetSprite(SpriteAsset* sprite)
	{
		m_Sprite = sprite;
	}
	SpriteAsset* SpriteComponent::GetSprite()
	{
		return m_Sprite;
	}
}
