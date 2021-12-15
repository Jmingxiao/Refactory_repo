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



void Game::Update()
{
	snake.Update();

	// Player colliding on theirself.

	const auto bodycolliding = [&](const auto& snakepart) noexcept {return snakepart._transform.GetPosition() == snake.transform.GetPosition(); };
	if (std::find_if(snake.snakeparts.begin(), snake.snakeparts.begin() + snake.snake_length, bodycolliding) != snake.snakeparts.begin()+snake.snake_length) {
		snake.ResetPlayer();
	}

	// Player going out of X bounds.
	if (snake.transform.GetX() > width || snake.transform.GetX() < 0||
		snake.transform.GetY() > height || snake.transform.GetY() < 0)
	{
		snake.ResetPlayer();
	}

	// Player collide on apple.
	if (snake.transform.GetPosition() == apple.trans.GetPosition())
	{
		snake.snake_length++;
		apple.trans.SetPosition(RandomPositionGenerator());
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
