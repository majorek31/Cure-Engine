#pragma once
#include "../../Objects/Object.h"
#include "../../Utils/Math.h"
#include "../../Macros.h"

namespace Cure {
	class CURE_API Camera : public Object {
	public:
		Camera(Vec2 pos, float fov);
		~Camera();
		Vec2 CalculateRelativePosition(Vec2 pos); 
	};
}