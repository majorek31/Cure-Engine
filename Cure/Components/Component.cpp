#include "Component.h"

namespace Cure {

	Cure::Object* Component::GetOwner()
	{
		return m_Owner;
	}

	void Component::SetOwner(Object* owner)
	{
		m_Owner = owner;
	}
}
