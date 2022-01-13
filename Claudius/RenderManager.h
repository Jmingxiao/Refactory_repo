#pragma once
#include <vector>
#include "Color.h"
#include "Rectangle.h"
#include "Vector2.h"
#include <memory>
#include "SDLSystem.h"

struct RenderManager
{
	struct RectEntry
	{
		const Rectangle rect;
		const Color color;
		const Vector2 transform;
	};

	RenderManager(SDL_Window* window) noexcept;
	void Render(const Rectangle& rect, const Color& color, const Vector2& trans) ;
	void Rendering() noexcept;
	SDL_Renderer* GetRenderer() const noexcept;
	void Clear() noexcept;
private:

	using renderer_ptr = std::unique_ptr<SDL_Renderer, Deleter>;
	renderer_ptr renderer;
	std::vector<RectEntry> rectEntries;
};
