#include "Image.h"

Image::Image(unsigned int id, int width, int height) noexcept : _id(id), _width(width), _height(height)
{
}

constexpr unsigned int Image::GetID() const noexcept
{
	return _id;
}

constexpr int Image::GetWidth() const noexcept
{
	return _width;
}

constexpr int Image::GetHeight() const noexcept
{
	return _height;
}
