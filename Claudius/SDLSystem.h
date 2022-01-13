#pragma once
#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning (disable:ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)

#include <memory>
#include <stdexcept>
#include "ConstValue.h"


struct Deleter
{
	void operator()(SDL_Renderer* tp)noexcept {
		SDL_DestroyRenderer(tp);
	}
	void operator()(SDL_Window* tp) noexcept {
		SDL_DestroyWindow(tp);
	}
};

class SDLWindow {
private:
	using window_ptr = std::unique_ptr<SDL_Window, Deleter>;
	window_ptr window;
public:
	SDLWindow() noexcept{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		}
		window = { SDL_CreateWindow("Base", 0, 0, 0, 0, SDL_WindowFlags::SDL_WINDOW_RESIZABLE),Deleter()};
		if (window == nullptr) {
			SDL_Log("Unable to initialise window: %s", SDL_GetError());
		}
	}
	void SetWindowConfig() noexcept {
		SDL_SetWindowSize(GetWindow(), Consts::SCR_Width,Consts::SCR_Height);
		SDL_SetWindowTitle(GetWindow(), Consts::title.c_str());
		SDL_SetWindowPosition(GetWindow(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	}

	SDL_Window* GetWindow() const noexcept {
		return window.get();
	}
};