#include "RenderManager.h"
#include "ResourceManager.h"
#include "Game.h"
#include "Sprite.h"
#include "Transform.h"
#include "Image.h"
#include <stdexcept>

#undef main

// ResourceManager 

struct ResourceImpl
{
	ResourceImpl(SDL_Renderer* renderer) noexcept : renderer(renderer) {};
	std::vector<std::pair<std::string, SDL_Texture*>> textures;
	SDL_Renderer* renderer;
	SDL_Texture* GetTexture(unsigned int id) noexcept
	{
		if (id < textures.size())
			return textures.at(id).second;
		else
			return nullptr;
	}
};

bool ResourceManager::LoadImageFromFile(Image& image, const std::string &filePath)
{
	auto it = impl.textures.begin();
	unsigned int index = 0;
	while (it != impl.textures.end())
	{
		if ((*it).first == filePath)
		{
			image._id = index;
			return true;
		}
		it++;
		index++;
	}
	SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
	if (surface != nullptr)
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(impl.renderer, surface);
		if (texture != nullptr)
		{
			impl.textures.push_back(std::pair<std::string, SDL_Texture*>(filePath, texture));
			image._id = static_cast<unsigned int>(impl.textures.size() - 1);
			image._width = surface->w;
			image._height = surface->h;
			return true;
		}
		else
		{
			throw std::runtime_error(SDL_GetError());
		}
	}
	else
	{
		throw std::runtime_error(SDL_GetError());
	}
	return false;
};

// RenderManager

struct RenderImpl
{
	SDL_Renderer* renderer;

};

void RenderManager::Render(const Sprite& sprite, const Transform& trans)
{
	spriteEntries.push_back({ sprite, trans });
}

void RenderManager::Render(const Rectangle& rect, const Color& color, const Transform& trans)
{
	rectEntries.push_back({ rect, color, trans });
}

void RenderManager::Clear() noexcept
{
	spriteEntries.clear();
	rectEntries.clear();
}

int main()
{
	using namespace KeyConfig;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Base", 0, 0, 0, 0, SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
	if (window == nullptr)
	{
		throw std::runtime_error(SDL_GetError());
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		throw std::runtime_error(SDL_GetError());
	}
	bool running = true;
	
	RenderManager renderManager;
	ResourceImpl resourceImpl(renderer);
	ResourceManager resourceManager(resourceImpl);
	Game game(resourceManager);

	
	SDL_SetWindowSize(window, Game::width, Game::height);
	SDL_SetWindowTitle(window, Game::title.c_str());
	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	

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

		SDL_SetRenderDrawColor(renderer,0,0,0,0);
		SDL_RenderClear(renderer);
		for (auto &&entry : renderManager.spriteEntries)
		{
			if (entry.sprite._image != nullptr)
			{
				SDL_Rect src{ entry.sprite.source._x, entry.sprite.source._y, entry.sprite.source._w, entry.sprite.source._h };
				SDL_Rect dst{ static_cast<int>(entry.trans._position.x),
							  static_cast<int>(entry.trans._position.y),
							  static_cast<int>(entry.sprite._image->_width),
							  static_cast<int>(entry.sprite._image->_height) };
				SDL_RenderCopy(renderer, resourceImpl.GetTexture(entry.sprite._image->_id), &src, &dst);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, entry.sprite.color._r, entry.sprite.color._g, entry.sprite.color._b, entry.sprite.color._a);
				SDL_Rect rect{ static_cast<int>(entry.trans._position.x),
							   static_cast<int>(entry.trans._position.y),
							   entry.sprite.source._w,
							   entry.sprite.source._h };
				SDL_RenderDrawRect(renderer, &rect);
			}
		}
		for (auto&& entry : renderManager.rectEntries)
		{
			SDL_SetRenderDrawColor(renderer, entry.color._r, entry.color._g, entry.color._b, entry.color._a);
			SDL_Rect rect{ static_cast<int>(entry.trans._position.x),
						   static_cast<int>(entry.trans._position.y),
						   entry.rect._w,
						   entry.rect._h };
			//SDL_RenderDrawRect(renderer, &rect);	// <- If you want to draw the "outline" of the rectangle.
			SDL_RenderFillRect(renderer, &rect);  // <- If you want to draw a "filled" rectangle. 
		}
		SDL_RenderPresent(renderer);
		renderManager.Clear();
		SDL_Delay(1000 / 20); //<- "Framerate".
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}
