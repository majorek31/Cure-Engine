#pragma once
#include <Cure.h>
class CoinCounter : public Cure::Object
{
public:
	CoinCounter() 
		: Object("CoinCounter")
	{
		AddComponent<Cure::TransformComponent>();
		auto collisionComp = AddComponent<Cure::CollisionComponent>();
		collisionComp->AddHitbox({ 0, 0, 52, 300 });
	}
};

