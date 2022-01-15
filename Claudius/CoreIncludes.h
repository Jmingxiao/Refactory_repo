#pragma once
#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning (disable:ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)

#include <memory>
#include <stdexcept>
#include "ConstValue.h"

struct Deleter {
	void operator()(SDL_Renderer* tp)noexcept {
		SDL_DestroyRenderer(tp);
	}
	void operator()(SDL_Window* tp) noexcept {
		SDL_DestroyWindow(tp);
	}
};