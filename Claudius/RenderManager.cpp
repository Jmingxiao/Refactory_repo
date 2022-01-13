#include "RenderManager.h"


RenderManager::RenderManager(SDL_Window* window) noexcept
{
	if (window != nullptr) {
		renderer = { SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED) ,Deleter() };
		if (renderer == nullptr) {
			SDL_Log("Unable to initialise renderer: %s", SDL_GetError());
		}
	}
}

void RenderManager::Render(const Rectangle& rect, const Color& color, const Vector2& trans)
{
	rectEntries.push_back({ rect, color, trans });
}

void RenderManager::Rendering() noexcept
{
	SDL_SetRenderDrawColor(GetRenderer(), 0, 0, 0, 0);
	SDL_RenderClear(GetRenderer());
	for (const auto& entry : rectEntries)
	{
		SDL_SetRenderDrawColor(GetRenderer(), entry.color._r, entry.color._g, entry.color._b, entry.color._a);
		SDL_Rect rect{ static_cast<int>(entry.transform.x),
					   static_cast<int>(entry.transform.y),
					   entry.rect._w,
					   entry.rect._h };
		SDL_RenderFillRect(GetRenderer(), &rect);
	}
	SDL_RenderPresent(GetRenderer());
}

SDL_Renderer* RenderManager::GetRenderer() const noexcept
{
	return renderer.get();
}

void RenderManager::Clear() noexcept
{
	rectEntries.clear();
}