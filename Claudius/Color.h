#pragma once

struct Color
{
	unsigned char _r, _g, _b, _a;

	Color() =default;
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept;

	void SetColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept;
};