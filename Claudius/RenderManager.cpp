#include "Renderer.h"


Renderer::Renderer(SDL_Window* window) {
	renderer = { SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED), Deleter() };
	if (renderer == nullptr) {
		throw std::runtime_error(SDL_GetError());
	}
}

void Renderer::enterFrame() const noexcept{
	SDL_SetRenderDrawColor(getPtr(), 0, 0, 0, Config::ALPHA_OPAQUE);
	SDL_RenderClear(getPtr());
}

void Renderer::Render(Vector2 pos, Color color) const noexcept{
	SDL_SetRenderDrawColor(getPtr(), color._r, color._g, color._b, color._a);
	SDL_Rect rectangle{ static_cast<int>(pos._x),
					static_cast<int>(pos._y),
					Config::TILE_SIZE,
					Config::TILE_SIZE };
	SDL_RenderFillRect(getPtr(), &rectangle);
}

void Renderer::exitFrame() const noexcept
{
	SDL_RenderPresent(getPtr());
}


SDL_Renderer* Renderer::getPtr() const noexcept
{
	return renderer.get();
}
