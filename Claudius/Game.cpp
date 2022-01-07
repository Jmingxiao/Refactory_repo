#include "Game.h"
#include "RenderManager.h"
#include <iostream>
#include "ConstValue.h"

bool Game::running = true;

void Game::Update() noexcept
{
	snake.Update();


	if (snake.CheckBodyCollision()) {
		snake.ResetPlayer();
	}


	if (snake.CheckOutSideBound(ConstValues::SCR_Width,ConstValues::SCR_Height))
	{
		snake.ResetPlayer();
	}

	if (snake.GetSnakeTransform().GetPosition() == apple.Gettransform().GetPosition())
	{
		snake.Score();
		apple.SetPosition(RandomPositionGenerator());
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