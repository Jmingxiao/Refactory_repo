#pragma once
#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning (disable:ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)
#include <memory>
#include <stdexcept>


struct RendererDeleter
{
	RendererDeleter() = default;
	void operator()(SDL_Renderer* tp)noexcept {
		SDL_DestroyRenderer(tp);
	}
};
struct WindowDeleter
{
	WindowDeleter() = default;
	void operator()(SDL_Window* tp) noexcept {
		SDL_DestroyWindow(tp);
	}
};

class SdlConfig {

private:
	std::unique_ptr<SDL_Window, WindowDeleter> window = nullptr;
	std::unique_ptr<SDL_Renderer, RendererDeleter>  renderer = nullptr;
public:
	SdlConfig() = default;
	void init() {
		SDL_Init(SDL_INIT_EVERYTHING);
		window = { SDL_CreateWindow("Base", 0, 0, 0, 0, SDL_WindowFlags::SDL_WINDOW_RESIZABLE),WindowDeleter() };
		if (window == nullptr) {
			throw std::runtime_error(SDL_GetError());
		}
		renderer = { SDL_CreateRenderer(GetWindow(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED) ,RendererDeleter()};
		if (renderer == nullptr) {
			throw std::runtime_error(SDL_GetError());
		}
	}

	SDL_Window* GetWindow() const noexcept {
		return window.get();
	}
	SDL_Renderer* GetRenderer() const noexcept {
		return renderer.get();
	}

};