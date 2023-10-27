#pragma once
#include "WindowParameters.h"
#include <SDL.h>
#include "../Macros.h"
#include "../Utils/Math.h"

namespace Cure {
	class CURE_API Window
	{
	public:
		Window(WindowParameters& params);
		~Window();

		void HandleEvents();

		void SetColor(SDL_Color color);
		void Clear();
		void RenderPresent();

		void RenderRectOutline(Vec2 pos, Vec2 size, SDL_Color color);
		void RenderRectFilled(Vec2 pos, Vec2 size, SDL_Color color);

		void RenderCircleOutline(Vec2 pos, float radius, SDL_Color);
	private:
		SDL_Window* m_SDLWindow;
		SDL_Renderer* m_SDLRenderer;
	};
}

