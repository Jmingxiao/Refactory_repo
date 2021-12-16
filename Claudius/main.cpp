#include "RenderManager.h"
#include "ResourceManager.h"
#include "Game.h"
#include "Sprite.h"
#include "Transform.h"
#include "Image.h"

#undef main


int main()
{
	using namespace KeyConfig;
	SdlConfig config{};
	config.init();

	bool running = true;
	
	RenderManager renderManager;
	ResourceManager resourceManager(config.GetRenderer());
	Game game{};

	
	SDL_SetWindowSize(config.GetWindow(), Game::width, Game::height);
	SDL_SetWindowTitle(config.GetWindow(), Game::title.c_str());
	SDL_SetWindowPosition(config.GetWindow(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	

	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT: running = false; break;
			case SDL_KEYDOWN: game.OnKeyDown(TranslateKeyCode(e.key.keysym.sym)); break;
			case SDL_KEYUP: break;
			default: break;
			}
		}

		game.Update();
		game.Render(renderManager);

		SDL_SetRenderDrawColor(config.GetRenderer(),0,0,0,0);
		SDL_RenderClear(config.GetRenderer());
		for (auto &&entry : renderManager.spriteEntries)
		{
			if (entry.sprite._image != nullptr)
			{
				SDL_Rect src{ entry.sprite.source._x, entry.sprite.source._y, entry.sprite.source._w, entry.sprite.source._h };
				SDL_Rect dst{ static_cast<int>(entry.transform.GetPosition().x),
							  static_cast<int>(entry.transform.GetPosition().y),
							  entry.sprite._image->GetWidth(),
							  entry.sprite._image->GetHeight()};
				SDL_RenderCopy(config.GetRenderer(), resourceManager.GetTexture(entry.sprite._image->GetID()), &src, &dst);
			}
			else
			{
				SDL_SetRenderDrawColor(config.GetRenderer(), entry.sprite.color._r, entry.sprite.color._g, entry.sprite.color._b, entry.sprite.color._a);
				SDL_Rect rect{ static_cast<int>(entry.transform.GetPosition().x),
							   static_cast<int>(entry.transform.GetPosition().y),
							   entry.sprite.source._w,
							   entry.sprite.source._h };
				SDL_RenderDrawRect(config.GetRenderer(), &rect);
			}
		}
		for (auto&& entry : renderManager.rectEntries)
		{
			SDL_SetRenderDrawColor(config.GetRenderer(), entry.color._r, entry.color._g, entry.color._b, entry.color._a);
			SDL_Rect rect{ static_cast<int>(entry.transform.GetPosition().x),
						   static_cast<int>(entry.transform.GetPosition().y),
						   entry.rect._w,
						   entry.rect._h };
			//SDL_RenderDrawRect(renderer, &rect);	// <- If you want to draw the "outline" of the rectangle.
			SDL_RenderFillRect(config.GetRenderer(), &rect);  // <- If you want to draw a "filled" rectangle. 
		}
		SDL_RenderPresent(config.GetRenderer());
		renderManager.Clear();
		SDL_Delay(1000 / 20); //<- "Framerate".
	}

	return 0;
}
