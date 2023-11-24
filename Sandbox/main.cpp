#include <Cure.h>
#include "Game/Components/BackgroundComponent.h"
#include "Game/Objects/Bird.h"
#include "Game/Objects/Pipe.h"

int main() {
	Cure::ApplicationParameters p;
	p.version = 0xFFAAFFAA;
	p.wndParams.flags = 0;
	p.wndParams.title = "Cure2D";
	p.wndParams.width = 800;
	p.wndParams.height = 600;
	p.frameRate = 120;
	Cure::Application* app = Cure::CreateApp(p);
	Cure::Scene* scene = new Cure::Scene();
	auto& assetMgr = Cure::AssetManager::Get();
	assetMgr.LoadAsset("background", new Cure::SpriteAsset("assets/background-day.png"));
	assetMgr.LoadAsset("bird-mid", new Cure::SpriteAsset("assets/bird-mid.png"));
	assetMgr.LoadAsset("pipe", new Cure::SpriteAsset("assets/pipe.png"));
	assetMgr.LoadAsset("debug_font", new Cure::FontAsset("C:/Windows/fonts/Arial.ttf", 16));
	app->GetSceneManager().LoadScene(scene);
	auto camera = scene->GetObjectManager().GetObjectByTag<Cure::Camera>("Camera");
	camera->AddComponent<BackgroundComponent>();
	scene->GetObjectManager().RegisterObject(new Bird());
	scene->GetObjectManager().RegisterObject(new Pipe(20));
	camera->AddComponent<Cure::DebugComponent>(Cure::ScanCode::KEY_F3);
	app->Run();
}