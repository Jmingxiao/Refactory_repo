#include "Color.h"


Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept  : _r(r), _g(g), _b(b), _a(a)
{
}

void Color::SetColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept
{
	_r = r; _g = g;
	_b = b; _a = a;
}
