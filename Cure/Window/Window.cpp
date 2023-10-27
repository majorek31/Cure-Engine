#include "Window.h"
#include "../Macros.h"
#include "../Application/Application.h"
#include "../Input/Input.h"

#include <SDL_ttf.h>

namespace Cure {

	Window::Window(WindowParameters& params)
	{
		m_SDLWindow = SDL_CreateWindow(params.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, params.width, params.height, params.flags);
		CURE_ASSERT(m_SDLWindow);
		m_SDLRenderer = SDL_CreateRenderer(m_SDLWindow, -1, 0);
		CURE_ASSERT(m_SDLRenderer);
	}

	Window::~Window()
	{
		SDL_DestroyRenderer(m_SDLRenderer);
		SDL_DestroyWindow(m_SDLWindow);
	}

	void Window::HandleEvents()
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_EventType::SDL_QUIT)
				Application::Get().Shutdown();
			Cure::Input::Get().Update(e);
		}
	}

	void Window::SetColor(SDL_Color color)
	{
		SDL_SetRenderDrawColor(m_SDLRenderer, color.r, color.g, color.b, color.a);
	}

	void Window::Clear()
	{
		SDL_RenderClear(m_SDLRenderer);
	}

	void Window::RenderPresent()
	{
		SDL_RenderPresent(m_SDLRenderer);
	}

	void Window::RenderRectOutline(Vec2 pos, Vec2 size, SDL_Color color)
	{
		SetColor(color);
		SDL_FRect rect;
		rect.x = pos.x;
		rect.y = pos.y;
		rect.w = size.x;
		rect.h = size.y;
		SDL_RenderDrawRectF(m_SDLRenderer, &rect);
	}

	void Window::RenderRectFilled(Vec2 pos, Vec2 size, SDL_Color color)
	{
		SetColor(color);
		SDL_FRect rect;
		rect.x = pos.x;
		rect.y = pos.y;
		rect.w = size.x;
		rect.h = size.y;
		SDL_RenderFillRectF(m_SDLRenderer, &rect);
	}

	void Window::RenderCircleOutline(Vec2 pos, float radius, SDL_Color color)
	{
		for (int a = 0; a < 360; a++) {
			float rads = a / (M_PI / 180);
			Vec2 point;
			point.x = pos.x + radius * cos(rads);
			point.y = pos.y + radius * sin(rads);
			SetColor(color);
			SDL_RenderDrawPointF(m_SDLRenderer, point.x, point.y);
		}
	}
	void Window::RenderText(Vec2 pos, FontAsset* font, const std::string& text, SDL_Color color)
	{
		SDL_Surface* surface = TTF_RenderText_Solid(font->GetNativeFont(), text.c_str(), color);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(m_SDLRenderer, surface);
		SDL_FRect rect = { pos.x, pos.y, surface->w, surface->h };
		SDL_RenderCopyF(m_SDLRenderer, texture, 0, &rect);

		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}
}