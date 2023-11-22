#include "Bird.h"
#include "../Components/BirdController.h"

Bird::Bird()
	: Object("Bird")
{
	auto& assets = Cure::AssetManager::Get();
	auto transform = AddComponent<Cure::TransformComponent>();
	transform->m_Position = { 100, 300 };
	auto birdController = AddComponent<BirdController>();
	auto spriteComponent = AddComponent<Cure::SpriteComponent>();
	spriteComponent->SetSprite(assets.GetAsset<Cure::SpriteAsset>("bird-mid"));
}
