#include "TagComponent.h"

namespace Cure {
	TagComponent::TagComponent(const std::string& tag) 
		: m_Tag(tag)
	{}

	TagComponent::~TagComponent()
	{
		m_Tag.erase();
	}

	void TagComponent::Start() {}

	void TagComponent::Update() {}

	void TagComponent::Render() {}

	const std::string& TagComponent::GetTag() const
	{
		return m_Tag;
	}
}