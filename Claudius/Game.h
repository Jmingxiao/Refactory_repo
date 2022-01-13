#pragma once

#include <string>
#include <vector>
#include "KeyCode.h"
#include "Player.h"

struct RenderManager;
struct ResourceManager;


class Game
{
	using Apple = Vector2;
	Snake snake{};
	Apple apple{100,100};

public:

	bool running = true;

	void Update() noexcept;
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key) noexcept;
	Vector2 RandomPositionGenerator() const noexcept;
};

