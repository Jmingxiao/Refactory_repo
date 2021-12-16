// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include <iostream>


const int Game::width = 1250;
const int Game::height = 700;
const std::string Game::title = "snake";

Game::Game() noexcept
{
	//Player test, moving two players to collide with each other.
	snake.Initialize();
	apple.Initialize(10, 10);
}



void Game::Update() noexcept
{
	snake.Update();

	// Player colliding on theirself.
	if (snake.CheckBodyCollision()) {
		snake.ResetPlayer();
	}

	// Player going out of bounds.
	if (snake.CheckOutSideBound(width,height))
	{
		snake.ResetPlayer();
	}

	// Player collide on apple.
	if (snake.transform.GetPosition() == apple.transform.GetPosition())
	{
		snake.Score();
		apple.transform.SetPosition(RandomPositionGenerator());
	}
}

void Game::Render(RenderManager& renderManager)
{
	snake.Render(renderManager);
	apple.Render(renderManager);
}

void Game::OnKeyDown(KeyConfig::KeyCode key) noexcept
{
	using namespace KeyConfig;
	snake.OnKeyDown(key);
}

constexpr Vector2 Game::RandomPositionGenerator() const noexcept
{
	constexpr int offset = 10;
	constexpr int randomwidth = 125 - offset*2;
	constexpr int randomheight = 70 - offset*2;
	constexpr float intance = 10.0f;
	const auto result = Vector2((offset+(rand() % randomwidth)) * intance, (offset+(rand() % randomheight)) * intance);
	return result;
}
