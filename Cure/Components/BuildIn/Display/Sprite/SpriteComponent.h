#pragma once
#include "../../../Component.h"
#include "../../Position/TransformComponent.h"
#include "../../../../Assets/Sprite/SpriteAsset.h"

namespace Cure {
	class SpriteComponent : Component
	{
	public:
		void Start();
		void Update();
		void Render();
		void SetSprite(SpriteAsset* sprite);
		SpriteAsset* GetSprite();
	private:
		TransformComponent* m_ObjectTransform;
		SpriteAsset* m_Sprite;
	};
}