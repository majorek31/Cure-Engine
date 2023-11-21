#include "SpriteComponent.h"
#include "../../../../Objects/Object.h"
#include "../../../../Application/Application.h"

namespace Cure {
	SpriteComponent::SpriteComponent(SpriteAsset* sprite)
		: m_Sprite(sprite),
		  m_ObjectTransform(nullptr)
	{

	}
	SpriteComponent::SpriteComponent()
		: m_Sprite(nullptr),
	   	  m_ObjectTransform(nullptr)
	{
	}
	void SpriteComponent::Start()
	{
		m_ObjectTransform = GetOwner()->GetComponent<TransformComponent>();
		CURE_ASSERT(m_ObjectTransform, "Object has no TransformComponent");
	}
	void SpriteComponent::Update()
	{

	}
	void SpriteComponent::Render()
	{
		if (!m_Sprite)
			return;
		Application::Get().GetWindow().RenderTexture(m_ObjectTransform->m_Position, m_Sprite, spriteSize, m_ObjectTransform->m_Angle);
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
