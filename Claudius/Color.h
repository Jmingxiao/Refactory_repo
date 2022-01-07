#pragma once

struct Color
{
	unsigned char _r, _g, _b, _a;
	static constexpr Color Green() noexcept {
		return Color(0, 255, 0, 0);
	}
	static constexpr Color Red() noexcept {
		return Color(255, 0, 0, 0);
	}
	static constexpr Color Blue() noexcept {
		return Color(0, 0, 255, 0);
	}
};