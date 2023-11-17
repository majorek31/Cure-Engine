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

	}
	void Render()
	{
		Cure::Application& app = Cure::Application::Get();
		Cure::Window& wnd = app.Get().GetWindow();
		Cure::Camera* cam = wnd.GetCamera();

		auto asset = Cure::AssetManager::Get().GetAsset<Cure::FontAsset>("comic_sans_16");
		std::stringstream ss;
		ss << "FPS: " << app.GetFPS() << "(frame time: " << app.GetDeltaTime() << "s)";
		wnd.RenderText({0, 0}, asset, ss.str(), Cure::COLOR_WHITE, true);
	}
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
		auto transform = GetOwner()->GetComponent<Cure::TransformComponent>();
		Cure::Application::Get().GetWindow().RenderRectFilled(transform->m_Position, {50, 50}, Cure::COLOR_WHITE);
	}

};
class Player : public Cure::Object {
public:
	Player() 
		: Object("Player")
	{
		AddComponent<Cure::TransformComponent>();
		AddComponent<MouseFollowerComponent>();
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

	app->GetSceneManager().LoadScene(scene);
	app->GetSceneManager().GetCurrentScene().GetObjectManager().GetObjectByTag<Cure::Camera>("Camera")->AddComponent<FPSComponent>();
	scene->GetObjectManager().RegisterObject(new Player());
	app->Run();

	delete app;
}
