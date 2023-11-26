#include "PipeController.h"
#include "../Objects/Pipe.h"
#include <sstream>
#include "../Objects/Bird.h"
#include "BirdController.h"
void PipeController::Start()
{
	m_Generator.seed(m_RandomDevice());
	m_LowerPipeDist = std::uniform_real_distribution<float>(0, 300);
}

void PipeController::Update() 
{
	auto collisionComponent = GetOwner()->GetComponent<Cure::CollisionComponent>();
	collisionComponent->ClearHitboxes();
	auto transform = GetOwner()->GetComponent<Cure::TransformComponent>();
	Pipe* pipe = dynamic_cast<Pipe*>(GetOwner());
	transform->m_Position.x -= 200 * Cure::Application::Get().GetDeltaTime();
	if (transform->m_Position.x < -Cure::AssetManager::Get().GetAsset<Cure::SpriteAsset>("pipe")->GetSize().x) {
		transform->m_Position.x = 900;
		pipe->SetLowerPos(m_LowerPipeDist(m_Generator));
	}
	float pipeGap = 300;
	float lowPart = pipe->GetLowerPos();

	collisionComponent->AddHitbox({ 0, 0, 52, lowPart + 22});
	collisionComponent->AddHitbox({ 0, lowPart + pipeGap, 52, 300});
	auto bird = Cure::Application::Get().GetSceneManager().GetCurrentScene().GetObjectManager().GetObjectByTag<Bird>("Bird");
	if (collisionComponent->HasEnteredCollision(bird)) {
		bird->GetComponent<BirdController>()->Restart();
		transform->m_Position.x = 900;
		pipe->SetLowerPos(m_LowerPipeDist(m_Generator));
	}
}

void PipeController::Render()
{
 	auto transform = GetOwner()->GetComponent<Cure::TransformComponent>();
	Pipe* pipe = dynamic_cast<Pipe*>(GetOwner());
	float lowPart = pipe->GetLowerPos();
	auto& window = Cure::Application::Get().GetWindow();
	float pipeGap = 300;
	window.RenderTexture({ transform->m_Position.x, lowPart + pipeGap }, Cure::AssetManager::Get().GetAsset<Cure::SpriteAsset>("pipe"));
	window.RenderTexture({ transform->m_Position.x, lowPart - pipeGap }, Cure::AssetManager::Get().GetAsset<Cure::SpriteAsset>("pipe"), 180.f);
	std::stringstream ss;
	ss << "low part: " << lowPart;
	window.RenderText({ 600, 0 }, Cure::AssetManager::Get().GetAsset<Cure::FontAsset>("debug_font"), ss.str(), Cure::COLOR_WHITE, true);
}
