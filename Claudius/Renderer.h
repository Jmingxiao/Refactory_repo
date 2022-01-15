#pragma once

#include <vector>
#include <memory>
#include "CoreIncludes.h"

#include "Color.h"
#include "Rectangle.h"
#include "Vector2.h"

class Renderer
{
public:
	Renderer(SDL_Window* window);		
	SDL_Renderer* getPtr() const noexcept;
	
	void enterFrame() const noexcept;
	void Render(Vector2 pos, Color color) const noexcept;
	void exitFrame() const noexcept;
private:
	using renderer_ptr = std::unique_ptr<SDL_Renderer, Deleter>;
	renderer_ptr renderer;

};
