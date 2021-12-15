#include "ResourceManager.h"
#include "Image.h"
#include <stdexcept>

ResourceManager::ResourceManager(SDL_Renderer* renderer_) noexcept
	: renderer{ renderer_ ,RendererDeleter()}
{}

constexpr bool ResourceManager::LoadImageFromFile(Image& image, const std::string& filePath) 
{
	auto it = textures.begin();
	unsigned int index = 0;
	while (it != textures.end())
	{
		if ((*it).first == filePath)
		{
			image.SetID(index);
			return true;
		}
		it++;
		index++;
	}
	SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
	if (surface != nullptr)
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.get(), surface);
		if (texture != nullptr)
		{
			textures.push_back(std::pair<std::string, SDL_Texture*>(filePath, texture));
			image = { static_cast<unsigned int>(textures.size() - 1), surface->w,surface->h };
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
}
 SDL_Texture* ResourceManager::GetTexture(unsigned int id) const noexcept
{
	 return id < textures.size() ? textures.at(id).second : nullptr;
}
