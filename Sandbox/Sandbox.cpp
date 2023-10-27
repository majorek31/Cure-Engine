#include <iostream>
#include <Cure.h>

class HelloComponent : public Cure::Component {
	
public:
	void Start() override
	{
		Cure::TagComponent* tagComp = GetOwner()->GetComponent<Cure::TagComponent>();
		std::cout << "Hello from " << tagComp->GetTag();
		m_Pos = { 0 };
	}

	void Update() override
	{
		Cure::Input& input = Cure::Input::Get();
		Cure::TransformComponent* transform = GetOwner()->GetComponent<Cure::TransformComponent>();
		if (input.IsKeyDown(Cure::ScanCode::KEY_ESCAPE))
			Cure::Application::Get().Shutdown();
		Vec2 mousePos = input.GetMousePos();
		mousePos -= {25, 25};
		Vec2 direction = mousePos - transform->m_Position;

		transform->m_Velocity = direction * 3;
	}

	void Render() override
	{
		Cure::Application::Get().GetWindow().SetColor({ 255, 0, 0, 255 });
		Cure::Application::Get().GetWindow().Clear();

		Cure::Application::Get().GetWindow().RenderRectFilled(GetOwner()->GetComponent<Cure::TransformComponent>()->m_Position, { 50, 50 }, { 0, 0, 255, 255 });
		Cure::Application::Get().GetWindow().RenderCircleOutline(Cure::Input::Get().GetMousePos(), 35.3553390593, { 0, 255, 0, 255 });
	}
	Vec2 m_Pos = { 0, 0 };
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

	Cure::Object* player = new Cure::Object("Player");
	player->AddComponent<Cure::TransformComponent>();
	player->AddComponent<HelloComponent>();
	scene->GetObjectManager().RegisterObject(player);

	app->GetSceneManager().LoadScene(scene);
	app->Run();

	delete app;
}