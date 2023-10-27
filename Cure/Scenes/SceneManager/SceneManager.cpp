#include "SceneManager.h"

namespace Cure {

	SceneManager::SceneManager()
		: m_CurrentScene(nullptr)
	{

	}

	SceneManager::~SceneManager()
	{
		for (const auto& pair : m_Scenes) {
			delete pair.second;
		}
	}

	void SceneManager::LoadScene(Scene* scene)
	{
		m_CurrentScene = scene;
	}

	Scene& SceneManager::GetCurrentScene()
	{
		return *m_CurrentScene;
	}

	void SceneManager::Start()
	{
		m_CurrentScene->Start();
	}

	void SceneManager::Update()
	{
		m_CurrentScene->Update();
	}

	void SceneManager::Render()
	{
		m_CurrentScene->Render();
	}

}