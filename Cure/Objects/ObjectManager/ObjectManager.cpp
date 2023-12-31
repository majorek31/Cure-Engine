#include "ObjectManager.h"
#include "../../Application/Application.h"

namespace Cure {
	ObjectManager::ObjectManager()
	{
		m_Objects.reserve(0xFFFF);
	}
	ObjectManager::~ObjectManager()
	{
		for (Object* obj : m_Objects)
		{
			delete obj;
		}
	}

	void ObjectManager::RegisterObject(Object* obj)
	{
		m_Objects.push_back(obj);
	}

	void ObjectManager::DestroyObject(Object* obj)
	{
		m_Objects.erase(std::find(m_Objects.begin(), m_Objects.end(), obj));
		delete obj;
	}

	int ObjectManager::GetObjectCount()
	{
		return m_Objects.size();
	}

	std::vector<Object*>& ObjectManager::GetAllObjects()
	{
		return m_Objects;
	}

	void ObjectManager::Start()
	{
		for (Object* obj : m_Objects)
		{
			for (const auto& entry : obj->m_Components) {
				entry.second->Start();
			}
		}
	}

	void ObjectManager::Update()
	{
		for (Object* obj : m_Objects)
		{
			for (const auto& entry : obj->m_Components) {
				entry.second->Update();
			}
		}
	}

	void ObjectManager::Render()
	{
		for (Object* obj : m_Objects)
		{
			for (const auto& entry : obj->m_Components) {
				entry.second->Render();
			}
		}
	}

}