#pragma once
#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning (disable:ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)
#include <string>
#include <vector>
#include "SdlConfig.h"

struct Image;
struct Sound;


struct ResourceManager
{
	ResourceManager() = default;
	ResourceManager(SDL_Renderer* renderer_) noexcept;
	constexpr bool LoadImageFromFile(Image& image, const std::string& filePath) ;
	SDL_Texture* GetTexture(unsigned int id) const noexcept;
private:
	std::vector<std::pair<std::string, SDL_Texture*>> textures;
	std::unique_ptr<SDL_Renderer, RendererDeleter>  renderer = nullptr;
};
