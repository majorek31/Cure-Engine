#include "MenuScene.h"
#include "../Components/BackgroundComponent.h"

MenuScene::MenuScene()
{
	auto camera = GetObjectManager().GetObjectByTag<Cure::Camera>("Camera");
	camera->AddComponent<BackgroundComponent>();
}
