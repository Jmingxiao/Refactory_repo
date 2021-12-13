#pragma once

#include "Rectangle.h"
#include "Color.h"

struct Image;
struct Sprite
{
	Sprite() = default;
	Sprite(const Image& image) noexcept;
	Sprite(Rectangle source, Color color, Image& image) noexcept;
	Sprite(int x, int y, int w, int h, Color color, Image& image) noexcept;
	Sprite(Rectangle source, char r, char g, char b, char a, Image& image) noexcept;
	Sprite(int x, int y, int w, int h, char r, char g, char b, char a, Image& image) noexcept;
	
	constexpr void SetImage(const Image& image) noexcept;
	void SetSource(int x, int y, int w, int h) noexcept;
	void SetColor(char r, char g, char b, char a) noexcept;

	Rectangle source;
	Color color;
	const Image* _image;
};