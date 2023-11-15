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
	void Component::Initialize()
	{
		if (m_IsInitialized)
			return;
		m_IsInitialized = true;
		Start();
	}
}
