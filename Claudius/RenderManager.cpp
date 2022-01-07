#include "RenderManager.h"


void RenderManager::Render(const Rectangle& rect, const Color& color, const Transform& trans)
{
	rectEntries.push_back({ rect, color, trans });
}

void RenderManager::Rendering(SDL_Renderer* renderer) noexcept
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	for (const auto& entry : rectEntries)
	{
		SDL_SetRenderDrawColor(renderer, entry.color._r, entry.color._g, entry.color._b, entry.color._a);
		SDL_Rect rect{ static_cast<int>(entry.transform.GetPosition().x),
					   static_cast<int>(entry.transform.GetPosition().y),
					   entry.rect._w,
					   entry.rect._h };
		SDL_RenderFillRect(renderer, &rect);
	}
	SDL_RenderPresent(renderer);
}

void RenderManager::Clear() noexcept
{
	rectEntries.clear();
}