#include "Game.h"

void Game::run() noexcept
{
	while (running) {
		Input();
		Update();
		Render();		
		SDL_Delay(Config::FRAME_DELAY);
	}
}

void Game::Input() noexcept{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT: running = false; break;
		case SDL_KEYDOWN: OnKeyDown(TranslateKeyCode(e.key.keysym.sym)); break;
		case SDL_KEYUP: break;
		default: break;
		}
	}

}

void Game::Update() noexcept
{
	snake.Update();
	if (snake.CheckBodyCollision()) {
		snake.ResetPlayer();
		return;
	}

	if (snake.CheckOutSideBound(Config::STAGE_WIDTH, Config::STAGE_HEIGHT))
	{
		snake.ResetPlayer();
		return;
	}

	if (snake.GetPosition() == apple)
	{
		snake.Grow();
		apple = RandomPositionGenerator();
	}
}

void Game::Render() const noexcept{
	renderer.enterFrame();
	snake.Render(renderer);
	renderer.Render(apple, Color::Red());
	renderer.exitFrame();
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