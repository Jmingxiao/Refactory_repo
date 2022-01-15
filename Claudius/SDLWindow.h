#pragma once
#include "CoreIncludes.h"

class SDLWindow {
private:
	using window_ptr = std::unique_ptr<SDL_Window, Deleter>;
	window_ptr window;
public:
	SDLWindow(std::string_view title, unsigned width, unsigned height) {
		window = { SDL_CreateWindow(title.data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WindowFlags::SDL_WINDOW_OPENGL), Deleter()};
		if (window == nullptr) {
			throw std::runtime_error(SDL_GetError());
		}
	}
	SDL_Window* getPtr() const noexcept {
		return window.get();
	}
};