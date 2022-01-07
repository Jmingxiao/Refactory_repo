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

class SDLSystem {
private:
	using window_ptr = std::unique_ptr<SDL_Window, Deleter>;
	using renderer_ptr = std::unique_ptr<SDL_Renderer, Deleter>;

	std::unique_ptr<SDL_Window, Deleter> window = nullptr;
	std::unique_ptr<SDL_Renderer, Deleter>  renderer = nullptr;


public:
	
	SDLSystem() {
		SDL_Init(SDL_INIT_EVERYTHING);
		window = { SDL_CreateWindow("Base", 0, 0, 0, 0, SDL_WindowFlags::SDL_WINDOW_RESIZABLE),Deleter() };
		if (window == nullptr) {
			throw std::runtime_error(SDL_GetError());
		}
		renderer = { SDL_CreateRenderer(GetWindow(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED) ,Deleter() };
		if (renderer == nullptr) {
			throw std::runtime_error(SDL_GetError());
		}
	}
	void SetWindow() noexcept {
		SDL_SetWindowSize(GetWindow(), ConstValues::SCR_Width,ConstValues::SCR_Height);
		SDL_SetWindowTitle(GetWindow(), ConstValues::title.c_str());
		SDL_SetWindowPosition(GetWindow(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	}

	SDL_Window* GetWindow() const noexcept {
		return window.get();
	}
	SDL_Renderer* GetRenderer() const noexcept {
		return renderer.get();
	}

};