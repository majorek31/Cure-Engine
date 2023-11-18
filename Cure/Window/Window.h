#pragma once
#include "WindowParameters.h"
#include <SDL.h>
#include "../Macros.h"
#include "../Utils/Math.h"

#include "../Assets/Font/FontAsset.h"
#include "../Assets/Sprite/SpriteAsset.h"
#include "Camera/Camera.h"

namespace Cure {
	class Camera;
	constexpr SDL_Color COLOR_WHITE = { 255, 255, 255, 255 };
	constexpr SDL_Color COLOR_BLACK = { 0, 0, 0, 255 };
	class CURE_API Window
	{
	public:
		Window(WindowParameters& params);
		~Window();

		void HandleEvents();
		void SetCamera(Camera* cam);
		Camera* GetCamera();
		Vec2 GetScreenSize();

		void SetColor(SDL_Color color);

		void Clear(SDL_Color color);
		void RenderPresent();

		void RenderRectOutline(Vec2 pos, Vec2 size, SDL_Color color);
		void RenderRectFilled(Vec2 pos, Vec2 size, SDL_Color color);

		void RenderCircleOutline(Vec2 pos, float radius, SDL_Color color);

		void RenderText(Vec2 pos, FontAsset* font, const std::string& text, SDL_Color color, bool blend = true);

		void RenderTexture(Vec2 pos, SpriteAsset* sprite);
		void RenderTexture(Vec2 pos, SpriteAsset* sprite, float angle);
		void RenderTexture(Vec2 pos, SpriteAsset* sprite, Vec2 size);
		void RenderTexture(Vec2 pos, SpriteAsset* sprite, Vec2 size, float angle);
	private:
		SDL_Texture* CreateTextureFromSurface(SDL_Surface* surf);
	private:
		SDL_Window* m_SDLWindow;
		SDL_Renderer* m_SDLRenderer;
		Camera* m_CurrentCamera;
		Vec2 m_ScreenSize;
		friend class SpriteAsset;
	};
}

