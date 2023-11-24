#pragma once
#include "../../Component.h"
#include "../../../Input/InputTypes.h"
namespace Cure {
	class CURE_API DebugComponent : public Component	{
	public:
		DebugComponent();
		DebugComponent(ScanCode toggleKey);
		void Start() override;
		void Update() override;
		void Render() override;
	private:
		ScanCode m_ToogleKey;
		bool m_IsShown;
	};
}