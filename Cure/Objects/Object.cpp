#include "Object.h"
#include "../Components/BuildIn/Tag/TagComponent.h"
namespace Cure {

	Object::Object(const std::string& tag)
	{
		m_Components.reserve(0x1000);
		AddComponent<TagComponent>(tag);
	}

	Object::Object()
		: Object("OBJECT")
	{

	}

	Object::~Object()
	{
		for (const auto& entry : m_Components)
		{
			delete entry.second;
		}
	}
}