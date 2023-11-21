#pragma once
#include "../../../Component.h"
#include "../../Position/TransformComponent.h"
#include "../../../../Assets/Sprite/SpriteAsset.h"

namespace Cure {
	class CURE_API SpriteComponent : Component
	{
	public:
		SpriteComponent(SpriteAsset* sprite);
		SpriteComponent();
		void Start();
		void Update();
		void Render();
		void SetSprite(SpriteAsset* sprite);
		SpriteAsset* GetSprite();
	private:
		TransformComponent* m_ObjectTransform;
		SpriteAsset* m_Sprite;
	public:
		Vec2 spriteSize = { 0, 0 };
	};
}