#pragma once
#include "../../Component.h"
#include <vector>
#include <SDL.h>

namespace Cure {
	class CURE_API CollisionComponent : public Component
	{
	public:
		CollisionComponent();
		CollisionComponent(SDL_FRect hitbox);
		void Start() override;
		void Update() override;
		void Render() override;

		bool HasCollision(Object* obj);
		bool HasEnteredCollision(Object* obj);

		// in the end hitbox position relative to object position
		void AddHitbox(SDL_FRect rect);
		void ClearHitboxes();
	private:
		std::vector<SDL_FRect> m_Hitboxes;
		std::vector<std::pair<bool, Object*>> m_Colliders;
	};
}

