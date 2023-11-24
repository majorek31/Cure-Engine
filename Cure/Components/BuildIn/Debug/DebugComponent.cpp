#include "DebugComponent.h"
#include "../../../Objects/ObjectManager/ObjectManager.h"
#include "../../../Application/Application.h"
#include "../../../Assets/AssetManager/AssetManager.h"
#include "../../../Input/Input.h"
#include <sstream>
namespace Cure {
	DebugComponent::DebugComponent()
		: m_ToogleKey(ScanCode::KEY_F3),
		  m_IsShown(true)
	{
	}
	DebugComponent::DebugComponent(ScanCode toggleKey)
		: m_ToogleKey(toggleKey),
		  m_IsShown(true)
	{
	}
	void DebugComponent::Start()
	{
	}
	void DebugComponent::Update()
	{
		if (Input::Get().GetKeyDown(m_ToogleKey))
			m_IsShown = !m_IsShown;
	}
	void DebugComponent::Render()
	{
		if (!m_IsShown)
			return;
		auto& app = Application::Get();
		auto& window = app.GetWindow();
		auto font = AssetManager::Get().GetAsset<FontAsset>("debug_font");
		std::stringstream ss;
		ss << "FPS: " << app.GetFPS() << " (" << app.GetDeltaTime() << "ms)";
		window.RenderText({ 0, 0 }, font, ss.str(), COLOR_WHITE, true);
		ss.str("");
		ss << "Objects: " << app.GetSceneManager().GetCurrentScene().GetObjectManager().GetObjectCount();
		window.RenderText({ 0, 16 }, font, ss.str(), COLOR_WHITE, true);
		ss.str("");
		ss << "Scene: 0x" << &app.GetSceneManager().GetCurrentScene();
		window.RenderText({ 0, 32 }, font, ss.str(), COLOR_WHITE, true);
		ss.str("");
	}
}