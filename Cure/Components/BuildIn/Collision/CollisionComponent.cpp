#include "CollisionComponent.h"
#include <algorithm>
#include "../Position/TransformComponent.h"
#include "../../../Objects/Object.h"
#include "../../../Application/Application.h"
namespace Cure {
	CollisionComponent::CollisionComponent()
	{
	}
	CollisionComponent::CollisionComponent(SDL_FRect hitbox)
	{
		m_Hitboxes.emplace_back(hitbox);
	}

	void CollisionComponent::Start()
	{
		CURE_ASSERT(GetOwner()->HasComponent<TransformComponent>(), "TransformComponent has to be present");
	}
	void CollisionComponent::Update() 
	{
		auto ownerTransform = GetOwner()->GetComponent<TransformComponent>();
		auto objects = Application::Get().GetSceneManager().GetCurrentScene().GetObjectManager().GetAllObjects();
		for (auto object : objects) {
			if (GetOwner() == object)
				continue;
			auto testObjectTransform = object->GetComponent<TransformComponent>();
			auto testObjectCollision = object->GetComponent<CollisionComponent>();			
			if (!testObjectCollision || !testObjectTransform)
				continue;
			for (SDL_FRect rect : m_Hitboxes) {
				SDL_FRect ownerTestRect = { rect.x + ownerTransform->m_Position.x, rect.y + ownerTransform->m_Position.y, rect.w, rect.h };
				for (SDL_FRect testRect : testObjectCollision->m_Hitboxes) {
					SDL_FRect colliderTestRect = { testRect.x + testObjectTransform->m_Position.x, testRect.y + testObjectTransform->m_Position.y, testRect.w, testRect.h };
					if (SDL_HasIntersectionF(&ownerTestRect, &colliderTestRect)) {
						if (HasCollision(object)) {
							for (auto& pair : m_Colliders) {
								if (pair.second == object) {
									pair.first = true;
									break;
								}
							}
						}
						else {
 							m_Colliders.emplace_back(std::make_pair(false, object));
						}
					}
					else {
						m_Colliders.erase(std::remove_if(m_Colliders.begin(), m_Colliders.end(), [object](auto& pair) {
							return pair.second == object;
						}), m_Colliders.end());
					}
				}
			}
		}
	}
	void CollisionComponent::Render()
	{
		for (auto& hitbox : m_Hitboxes) {
			auto transform = GetOwner()->GetComponent<TransformComponent>();
			Cure::Application::Get().GetWindow().RenderRectOutline(transform->m_Position, { hitbox.w, hitbox.h}, {255, 0, 0, 255});
		}
	}

	bool CollisionComponent::HasCollision(Object* obj)
	{
		for (auto& pair : m_Colliders) {
			if (pair.second == obj)
				return true;
		}
		return false;
	}

	bool CollisionComponent::HasEnteredCollision(Object* obj)
	{
		for (auto& pair : m_Colliders) {
			if (pair.second == obj && pair.first == false)
				return true;
		}
		return false;
	}

	void CollisionComponent::AddHitox(SDL_FRect rect)
	{
		m_Hitboxes.emplace_back(rect);
	}

	void CollisionComponent::ClearHitboxes()
	{
		m_Hitboxes.clear();
	}

}