#include "Rectangle.h"


Rectangle::Rectangle(int x, int y, int w, int h) noexcept : _x(x), _y(y), _w(w), _h(h)
{
}

void Rectangle::SetBounds(int x, int y, int w, int h) noexcept
{
	_x = x; _y = y; _w = w; _h = h;
}
