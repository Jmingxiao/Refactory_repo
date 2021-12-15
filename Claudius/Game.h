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
	Snake snake;
	Apple apple;

public:

	static const int width;
	static const int height;
	static const std::string title;

	Game() noexcept;
	//bool Enter(int& width, int& height, std::string& title);
	void Update();
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyConfig::KeyCode key) noexcept;

	constexpr Vector2 RandomPositionGenerator() const noexcept;
};