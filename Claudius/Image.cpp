#include "Image.h"

Image::Image(unsigned int id, int width, int height) noexcept : _id(id), _width(width), _height(height)
{
}

const void Image::SetID(const unsigned int id) noexcept
{
	_id = id;
}

constexpr void Image::SetWidth(const int width) noexcept
{
	_width = width;
}

constexpr void Image::SetHeight(const int height) noexcept
{
	_height	= height;
}

const unsigned int Image::GetID() const noexcept
{
	return _id;
}

const int Image::GetWidth() const noexcept
{
	return _width;
}

 const int Image::GetHeight() const noexcept
{
	return _height;
}
