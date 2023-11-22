#pragma once
#include "../../Component.h"
namespace Cure {
	class CURE_API DebugComponent : public Component	{
	public:
		void Start() override;
		void Update() override;
		void Render() override;
	};
}