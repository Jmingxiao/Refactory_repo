#pragma once

#include <string>

struct Image;
struct Sound;
struct ResourceImpl;

struct ResourceManager
{
	ResourceManager(ResourceImpl& impl) noexcept : impl(impl) {};
	
	bool LoadImageFromFile(Image& image, const std::string &filePath);
private:
	ResourceImpl& impl;
};
