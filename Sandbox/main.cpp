#include <Cure.h>
#include "Game/Components/BackgroundComponent.h"
#include "Game/Objects/Bird.h"
#include "Game/Objects/Pipe.h"
#include "Game/Scenes/GameScene.h"
#include "Game/Scenes/MenuScene.h"

int main() {
	Cure::ApplicationParameters p;
	p.version = 0xFFAAFFAA;
	p.wndParams.flags = 0;
	p.wndParams.title = "Cure2D";
	p.wndParams.width = 800;
	p.wndParams.height = 600;
	p.frameRate = 120;
	Cure::Application* app = Cure::CreateApp(p);
	auto& assetMgr = Cure::AssetManager::Get();
	assetMgr.LoadAsset("background", new Cure::SpriteAsset("assets/background-day.png"));
	assetMgr.LoadAsset("bird-mid", new Cure::SpriteAsset("assets/bird-mid.png"));
	assetMgr.LoadAsset("pipe", new Cure::SpriteAsset("assets/pipe.png"));
	assetMgr.LoadAsset("debug_font", new Cure::FontAsset("C:/Windows/fonts/Arial.ttf", 16));
	assetMgr.LoadAsset("wing", new Cure::AudioAsset("assets/audio/audio_wing.wav", Cure::AudioType::WAV));
	app->GetSceneManager().LoadScene(new MenuScene());

	app->Run();
}