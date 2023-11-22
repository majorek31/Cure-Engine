#include "BackgroundComponent.h"

void BackgroundComponent::Start()
{

}

void BackgroundComponent::Update()
{

}

void BackgroundComponent::Render()
{
	Cure::Application::Get().GetWindow().RenderTexture({ 0, 0 }, Cure::AssetManager::Get().GetAsset<Cure::SpriteAsset>("background"), { 800, 600 });
}
