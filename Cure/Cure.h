#pragma once

#ifndef _WIN32
	#error We only support Window for now
#endif
// -----------
#include "Macros.h"
// -----= Application =------
#include "Application/ApplicationParameters.h"
#include "Application/Application.h"
// -----= Window =------
#include "Window/Window.h"
// -----= Scenes =------
#include "Scenes/Scene.h"
#include "Scenes/SceneManager/SceneManager.h"
// -----------
#include "Objects/ObjectManager/ObjectManager.h"
// -----------

#include "Components/BuildIn/Tag/TagComponent.h"
#include "Components/BuildIn/Position/TransformComponent.h"

#include "Input/Input.h"
#include "Utils/Math.h"
#include "Utils/DebugTimer.h"