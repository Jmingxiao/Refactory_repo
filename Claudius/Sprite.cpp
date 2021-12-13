#include "Sprite.h"


Sprite::Sprite(const Image& image) noexcept : source(0, 0, 0, 0), color(0, 0, 0, 0), _image(&image)
{
}

Sprite::Sprite(Rectangle source, Color color, Image& image) noexcept : source(source), color(color), _image(&image)
{
}

Sprite::Sprite(int x, int y, int w, int h, Color color, Image& image) noexcept : source(x,y,w,h), color(color), _image(&image)
{
}

Sprite::Sprite(Rectangle source, char r, char g, char b, char a, Image& image) noexcept : source(source), color(r,g,b,a), _image(&image)
{
}

Sprite::Sprite(int x, int y, int w, int h, char r, char g, char b, char a, Image& image) noexcept : source(x,y,w,h), color(r,g,b,a), _image(&image)
{
}

constexpr void Sprite::SetImage(const Image& image) noexcept
{
	this->_image = &image;
}

void Sprite::SetSource(int x, int y, int w, int h) noexcept
{
	source.SetBounds(x, y, w, h);
}

void Sprite::SetColor(char r, char g, char b, char a) noexcept
{
	color.SetColor(r, g, b, a);
}
