#pragma once
#include "SDLSystem.h"
#include "SDLWindow.h"
#include "Renderer.h"
#include "KeyCode.h"
#include "Player.h"
#include "CoreIncludes.h"

class Game
{
	using Apple = Vector2;
	SDLSystem sdl{ SDL_INIT_EVERYTHING };
	SDLWindow window{ Config::TITLE, Config::STAGE_WIDTH, Config::STAGE_HEIGHT };
	Renderer renderer{ window.getPtr() };

	Snake snake{};
	Apple apple{Config::APPLE_STARTPOS};
	bool running = true;
	void Input() noexcept;
	void Update() noexcept;
	void Render() const noexcept;
	void OnKeyDown(KeyCode key) noexcept;
	Vector2 RandomPositionGenerator() const noexcept;

public:	
	void run() noexcept;	
};

