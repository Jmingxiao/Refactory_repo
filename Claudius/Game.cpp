#include "Game.h"
#include "RenderManager.h"
#include <iostream>
#include "ConstValue.h"

void Game::Update() noexcept
{
	snake.Update();
	if (snake.CheckBodyCollision()) {
		snake.ResetPlayer();
		return;
	}

	if (snake.CheckOutSideBound(Consts::SCR_Width,Consts::SCR_Height))
	{
		snake.ResetPlayer();
		return;
	}

	if (snake.Gettransform() == apple)
	{
		snake.Score();
		apple = RandomPositionGenerator();
	}
}

void Game::Render(RenderManager& renderManager)
{
	snake.Render(renderManager);
	renderManager.Render({ 0,0,Consts::appleSize,Consts::appleSize }, Consts::appleColor, apple);
}

void Game::OnKeyDown(KeyCode key) noexcept
{
	snake.OnKeyDown(key);
}

Vector2 Game::RandomPositionGenerator() const noexcept
{
	constexpr float offset = 10.0f;
	const float newPosX = (rand() % 100) * offset;
	const float newPosY = (rand() % 70) * offset;
	return { newPosX, newPosY };
}