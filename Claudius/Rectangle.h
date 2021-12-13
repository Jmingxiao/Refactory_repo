#pragma once

typedef struct Rectangle
{
	int _x{}; 
	int _y{};
	int _w{}; 
	int _h{};

	Rectangle() = default;
	Rectangle(int x, int y, int w, int h) noexcept;

	void SetBounds(int x, int y, int w, int h) noexcept;
} Collider;