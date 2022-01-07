#include "RenderManager.h"
#include "Game.h"
#include "Transform.h"
#include "SDLSystem.h"

#undef main

void PollEvent(Game& game) noexcept
{
	using namespace KeyConfig;
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT: Game::running = false; break;
		case SDL_KEYDOWN: game.OnKeyDown(TranslateKeyCode(e.key.keysym.sym)); break;
		case SDL_KEYUP: break;
		default: break;
		}
	}
}

int main()
{
	SDLSystem config(SDL_INIT_EVERYTHING);
	config.SetWindowConfig();
	
	RenderManager renderManager{};
	Game game{};
	
	while (Game::running)
	{
		PollEvent(game);

		game.Update();
		game.Render(renderManager);
		renderManager.Rendering(config.GetRenderer());
		renderManager.Clear();
		
		SDL_Delay(ConstValues::FrameRate);
	}
	return 0;
}
