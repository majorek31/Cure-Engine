#include "Object.h"
#include "../Components/BuildIn/Tag/TagComponent.h"
namespace Cure {

	Object::Object(const std::string& tag)
	{
		AddComponent<TagComponent>(tag);
	}

	Object::Object()
	{
		AddComponent<TagComponent>("OBJECT");
	}

	Object::~Object()
	{
		for (const auto& entry : m_Components)
		{
			delete entry.second;
		}
	}
}