#include "Bird.h"
#include "../Components/BirdController.h"

Bird::Bird()
	: Object("Bird")
{
	auto& assets = Cure::AssetManager::Get();
	auto transform = AddComponent<Cure::TransformComponent>();
	auto birdController = AddComponent<BirdController>();
	auto spriteComponent = AddComponent<Cure::SpriteComponent>();
	SDL_FRect hitbox = { 0.f, 0.f, 34.f, 24.f };
	auto collisionComponent = AddComponent<Cure::CollisionComponent>(hitbox);
	spriteComponent->SetSprite(assets.GetAsset<Cure::SpriteAsset>("bird-mid"));
}
