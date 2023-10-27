#pragma once
#include <iostream>
#include "../../Component.h"

namespace Cure {
	class CURE_API TagComponent : public Cure::Component
	{
	public:
		TagComponent(const std::string& tag);
		~TagComponent();
		void Start() override;
		void Update() override;
		void Render() override;
		const std::string& GetTag() const;
	private:
		std::string m_Tag;
	};
}