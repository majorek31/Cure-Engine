#include "Scene.h"
#include "../Window/Camera/Camera.h"

namespace Cure {

	Scene::Scene()
	{
		m_ObjectManager = new ObjectManager();
		m_ObjectManager->RegisterObject(dynamic_cast<Object*>(new Camera({ 0, 0 }, 0)));
	}

	Scene::~Scene()
	{
		delete m_ObjectManager;
	}

	ObjectManager& Scene::GetObjectManager()
	{
		return *m_ObjectManager;
	}

	void Scene::Start()
	{
		m_ObjectManager->Start();
	}

	void Scene::Update()
	{
		m_ObjectManager->Update();
	}

	void Scene::Render()
	{
		m_ObjectManager->Render();
	}

}