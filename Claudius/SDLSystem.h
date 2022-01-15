#pragma once
#include "CoreIncludes.h"

struct SDLSystem{

	SDLSystem() = delete;
	SDLSystem(const SDLSystem&) = delete;
	SDLSystem(SDLSystem&&) = delete;
	SDLSystem& operator=(const SDLSystem& ) = delete;
	SDLSystem& operator=(SDLSystem&&) = delete;

	SDLSystem(unsigned flags) {
		if (SDL_Init(flags) != 0) {			
			throw std::runtime_error(SDL_GetError());
		}
	}
	~SDLSystem() {
		SDL_Quit();
	}
};