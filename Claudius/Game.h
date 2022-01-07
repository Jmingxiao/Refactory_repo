#pragma once

#include <string>
#include <vector>
#include "KeyCode.h"
#include "Apple.h"
#include "Player.h"

struct RenderManager;
struct ResourceManager;




class Game
{
	Snake snake{};
	Apple apple{};

public:

	static bool running;

	void Update() noexcept;
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyConfig::KeyCode key) noexcept;

	constexpr Vector2 RandomPositionGenerator() const noexcept;
};

