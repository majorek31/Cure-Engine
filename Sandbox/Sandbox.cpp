#include <iostream>
#include <sstream>
#include <Cure.h>
class FPSComponent : public Cure::Component {
public:
	void Start()
	{
		std::cout << "Hello from " << GetOwner()->GetComponent<Cure::TagComponent>()->GetTag() << "\n";
	}
	void Update()
	{
		if (Cure::Input::Get().GetMouse(Cure::MouseButton::LEFT))
			m_ClickCount++;
		if (Cure::Input::Get().GetKeyDown(Cure::ScanCode::KEY_H))
			m_ShowFPS = !m_ShowFPS;
	}
	void Render()
	{
		Cure::Application& app = Cure::Application::Get();
		Cure::Window& wnd = app.Get().GetWindow();
		Cure::Camera* cam = wnd.GetCamera();

		auto asset = Cure::AssetManager::Get().GetAsset<Cure::FontAsset>("comic_sans_16");
		std::stringstream ss;
		ss << "FPS: " << app.GetFPS() << "(frame time: " << app.GetDeltaTime() << "s) " << "Clicks: " << m_ClickCount;
		wnd.RenderTexture({ 0, 0 }, Cure::AssetManager::Get().GetAsset<Cure::SpriteAsset>("background"));
		if (m_ShowFPS)
			wnd.RenderText({0, 0}, asset, ss.str(), Cure::COLOR_WHITE);
	}
private:
	int m_ClickCount = 0;
	bool m_ShowFPS = true;
};
class MouseFollowerComponent : public Cure::Component 
{
public:
	void Start() override
	{

	}


	void Update() override
	{
		auto transform = GetOwner()->GetComponent<Cure::TransformComponent>();
		Vec2 direction = Cure::Input::Get().GetMousePos() - transform->m_Position;
		transform->m_Velocity = direction;
	}


	void Render() override
	{

	}

};
class Player : public Cure::Object {
public:
	Player() 
		: Object("Player")
	{
		AddComponent<Cure::TransformComponent>();
		AddComponent<MouseFollowerComponent>();
		auto asset = Cure::AssetManager::Get().GetAsset<Cure::SpriteAsset>("star_img");
		auto spriteComp = AddComponent<Cure::SpriteComponent>(asset);
		spriteComp->spriteSize = { 50, 50 };

	}
};

int main()
{
	Cure::ApplicationParameters p;
	p.version = 0xFFAAFFAA;
	p.wndParams.flags = 0;
	p.wndParams.title = "Cure2D";
	p.wndParams.width = 1200;
	p.wndParams.height = 800;
	p.frameRate = 120;
	Cure::Application* app = Cure::CreateApp(p);
	Cure::Scene* scene = new Cure::Scene();
	Cure::AssetManager::Get().LoadAsset("arial_16", new Cure::FontAsset("C:/Windows/fonts/Arial.ttf", 16));
	Cure::AssetManager::Get().LoadAsset("comic_sans_16", new Cure::FontAsset("C:/Windows/fonts/Comic.ttf", 16));
	Cure::AssetManager::Get().LoadAsset("star_img", new Cure::SpriteAsset("star.png"));
	Cure::AssetManager::Get().LoadAsset("background", new Cure::SpriteAsset("background.jpg"));

	app->GetSceneManager().LoadScene(scene);
	app->GetSceneManager().GetCurrentScene().GetObjectManager().GetObjectByTag<Cure::Camera>("Camera")->AddComponent<FPSComponent>();
	scene->GetObjectManager().RegisterObject(new Player());
	app->Run();

	delete app;
}
