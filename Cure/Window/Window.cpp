#include "Window.h"
#include "../Macros.h"
#include "../Application/Application.h"
#include "../Input/Input.h"

#include <SDL_ttf.h>
#include "../Assets/Sprite/SpriteAsset.h"

namespace Cure {

	Window::Window(WindowParameters& params)
	{
		m_SDLWindow = SDL_CreateWindow(params.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, params.width, params.height, params.flags);
		CURE_ASSERT(m_SDLWindow, SDL_GetError());
		m_SDLRenderer = SDL_CreateRenderer(m_SDLWindow, -1, 0);
		CURE_ASSERT(m_SDLRenderer, SDL_GetError());
		m_ScreenSize = { 
			static_cast<float>(params.width),
			static_cast<float>(params.height)
		};
	}

	Window::~Window()
	{
		SDL_DestroyRenderer(m_SDLRenderer);
		SDL_DestroyWindow(m_SDLWindow);
	}

	void Window::HandleEvents()
	{
		SDL_Event e;
		Cure::Input::Get().ClearInputs();
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_EventType::SDL_QUIT)
				Application::Get().Shutdown();
			Cure::Input::Get().Update(e);
		}
	}

	void Window::SetCamera(Camera* cam)
	{
		m_CurrentCamera = cam;
	}

	Camera* Window::GetCamera()
	{
		return m_CurrentCamera;
	}

	Vec2 Window::GetScreenSize()
	{
		return m_ScreenSize;
	}

	void Window::SetColor(SDL_Color color) {
		SDL_SetRenderDrawColor(m_SDLRenderer, color.r, color.g, color.b, color.a);

	}
	void Window::Clear(SDL_Color color)
	{
		SetColor(color);
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
	void Window::RenderText(Vec2 pos, FontAsset* font, const std::string& text, SDL_Color color, bool blend)
	{
		SDL_Surface* surface = nullptr;
		if (blend)
			surface = TTF_RenderText_Blended(font->GetNativeFont(), text.c_str(), color);
		else 
			surface = TTF_RenderText_Solid(font->GetNativeFont(), text.c_str(), color);
		CURE_ASSERT(surface, SDL_GetError());

		SDL_Texture* texture = SDL_CreateTextureFromSurface(m_SDLRenderer, surface);
		SDL_FRect rect = { pos.x, pos.y, surface->w, surface->h };
		SDL_RenderCopyF(m_SDLRenderer, texture, 0, &rect);

		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}
	void Window::RenderTexture(Vec2 pos, SpriteAsset* sprite) {
		RenderTexture(pos, sprite, { 0, 0 });
	}
	void Window::RenderTexture(Vec2 pos, SpriteAsset* sprite, Vec2 size) {
		RenderTexture(pos, sprite, size, 0);
	}
	void Window::RenderTexture(Vec2 pos, SpriteAsset* sprite, float angle) {
		RenderTexture(pos, sprite, { 0, 0 }, angle);
	}
	void Window::RenderTexture(Vec2 pos, SpriteAsset* sprite, Vec2 size, float angle)
	{
		if (!size.x || !size.y)
			size = sprite->GetSize();
		SDL_FRect rect;
		rect.x = pos.x;
		rect.y = pos.y;
		rect.w = size.x;
		rect.h = size.y;
			
		SDL_FPoint center;
		center.x = pos.x + size.x / 2;
		center.y = pos.y + size.y / 2;
		SDL_RenderCopyExF(m_SDLRenderer, sprite->GetTexture(), 0, &rect, angle, &center, SDL_FLIP_NONE);
	}
	SDL_Texture* Window::CreateTextureFromSurface(SDL_Surface* surf)
	{
		return SDL_CreateTextureFromSurface(m_SDLRenderer, surf);
	}
}
