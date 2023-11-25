#include "GameScene.h"
#include "../Components/BackgroundComponent.h"
#include "../Objects/Bird.h"
#include "../Objects/Pipe.h"

GameScene::GameScene()
{
	auto camera = GetObjectManager().GetObjectByTag<Cure::Camera>("Camera");
	camera->AddComponent<BackgroundComponent>();
	GetObjectManager().RegisterObject(new Bird());
	GetObjectManager().RegisterObject(new Pipe(20));
	camera->AddComponent<Cure::DebugComponent>(Cure::ScanCode::KEY_F3);
}
