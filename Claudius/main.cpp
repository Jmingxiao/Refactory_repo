#include "RenderManager.h"
#include "Game.h"
#include "SDLSystem.h"

#undef main

void PollEvent(Game& game) noexcept
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT: game.running = false; break;
		case SDL_KEYDOWN: game.OnKeyDown(TranslateKeyCode(e.key.keysym.sym)); break;
		case SDL_KEYUP: break;
		default: break;
		}
	}
}

int main()
{
	SDLWindow config{};
	RenderManager renderManager(config.GetWindow());
	config.SetWindowConfig();

	Game game{};
	while (game.running)
	{
		PollEvent(game);

		game.Update();
		game.Render(renderManager);
		renderManager.Rendering();
		renderManager.Clear();
		
		SDL_Delay(Consts::FrameRate);
	}
	return 0;
}
