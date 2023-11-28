#include "PipeController.h"
#include "../Objects/Pipe.h"
#include <sstream>
#include "../Objects/Bird.h"
#include "BirdController.h"
#include "../Objects/CoinCounter.h"
void PipeController::Start()
{
	m_Generator.seed(m_RandomDevice());
	m_LowerPipeDist = std::uniform_real_distribution<float>(0, 300);
}

void PipeController::Update() 
{
	auto counterObject = Cure::Application::Get().GetSceneManager().GetCurrentScene().GetObjectManager().GetObjectByTag<CoinCounter>("CoinCounter");
	auto collisionComponent = GetOwner()->GetComponent<Cure::CollisionComponent>();
	collisionComponent->ClearHitboxes();
	auto transform = GetOwner()->GetComponent<Cure::TransformComponent>();
	Pipe* pipe = dynamic_cast<Pipe*>(GetOwner());
	transform->m_Position.x -= 200 * Cure::Application::Get().GetDeltaTime();
	if (transform->m_Position.x < -Cure::AssetManager::Get().GetAsset<Cure::SpriteAsset>("pipe")->GetSize().x) {
		transform->m_Position.x = 900;
		pipe->SetLowerPos(m_LowerPipeDist(m_Generator));
		m_CollidedThisFrame = false;
	}
	float pipeGap = 300;
	float lowPart = pipe->GetLowerPos();
	counterObject->GetComponent<Cure::TransformComponent>()->m_Position = transform->m_Position;
	counterObject->GetComponent<Cure::TransformComponent>()->m_Position.y = lowPart + 22;
	collisionComponent->AddHitbox({ 0, 0, 52, lowPart + 22});
	collisionComponent->AddHitbox({ 0, lowPart + pipeGap, 52, 300});
	auto bird = Cure::Application::Get().GetSceneManager().GetCurrentScene().GetObjectManager().GetObjectByTag<Bird>("Bird");
	if (collisionComponent->HasEnteredCollision(bird)) {
		bird->GetComponent<BirdController>()->Restart();
		transform->m_Position.x = 900;
		pipe->SetLowerPos(m_LowerPipeDist(m_Generator));
	}
	if (bird->GetComponent<Cure::CollisionComponent>()->HasEnteredCollision(counterObject) && !m_CollidedThisFrame) {
		bird->GetComponent<BirdController>()->IncreasePoints();
		m_CollidedThisFrame = true;
	}
}

void PipeController::Render()
{
	auto transform = GetOwner()->GetComponent<Cure::TransformComponent>();
	Pipe* pipe = dynamic_cast<Pipe*>(GetOwner());
	float lowPart = pipe->GetLowerPos();
	auto& window = Cure::Application::Get().GetWindow();
	float pipeGap = 300;
	auto bird = Cure::Application::Get().GetSceneManager().GetCurrentScene().GetObjectManager().GetObjectByTag<Bird>("Bird");
	std::stringstream ss;
	ss << "Points: " << bird->GetComponent<BirdController>()->GetPoints();
	window.RenderText({ 440, 0 }, Cure::AssetManager::Get().GetAsset<Cure::FontAsset>("debug_font"), ss.str(), Cure::COLOR_WHITE, true);
	window.RenderTexture({ transform->m_Position.x, lowPart + pipeGap }, Cure::AssetManager::Get().GetAsset<Cure::SpriteAsset>("pipe"));
	window.RenderTexture({ transform->m_Position.x, lowPart - pipeGap }, Cure::AssetManager::Get().GetAsset<Cure::SpriteAsset>("pipe"), 180.f);
	ss.str("");
	ss << "low part: " << lowPart;
	window.RenderText({ 600, 0 }, Cure::AssetManager::Get().GetAsset<Cure::FontAsset>("debug_font"), ss.str(), Cure::COLOR_WHITE, true);
}
