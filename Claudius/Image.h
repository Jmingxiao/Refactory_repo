#pragma once

struct Image
{
	Image() = default;
	Image(unsigned int id, int width, int height) noexcept;

	unsigned int _id;
	int _width;
	int _height;

	constexpr unsigned int GetID() const noexcept;
	constexpr int GetWidth() const noexcept;
	constexpr int GetHeight() const noexcept;
};