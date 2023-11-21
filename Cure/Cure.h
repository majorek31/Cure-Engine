#pragma once

#ifndef _WIN32
	#error We only support Windows for now
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
#include "Components/BuildIn/Display/Sprite/SpriteComponent.h"

#include "Input/Input.h"
#include "Utils/Math.h"
#include "Utils/DebugTimer.h"

#include "Assets/Asset.h"
#include "Assets/Font/FontAsset.h"
#include "Assets/Sprite/SpriteAsset.h"
#include "Assets/AssetManager/AssetManager.h"

#include "Window/Camera/Camera.h"