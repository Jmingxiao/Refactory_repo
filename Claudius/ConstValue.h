#pragma once

#include <string_view>
#include "Vector2.h"
#include "Color.h"

namespace Config {
	constexpr unsigned ALPHA_OPAQUE = 255;
	constexpr unsigned ALPHA_TRANSPARENT = 0;
	 constexpr unsigned int FRAME_DELAY = 50u;
	 constexpr int STAGE_WIDTH = 1000;
	 constexpr int STAGE_HEIGHT = 700;
	 constexpr unsigned int TILE_SIZE = 10;
	 constexpr unsigned int APPLE_SIZE = TILE_SIZE;
	 constexpr unsigned int SNAKE_UNIT_SIZE = TILE_SIZE;
	 constexpr float SNAKE_SPEED = TILE_SIZE;
	 constexpr Vector2 SNAKE_STARTPOS{300,300};
	 constexpr Vector2 APPLE_STARTPOS{ 100,100 };
	 constexpr Vector2 LEFT{-1.0f,0.0f};
	 constexpr Vector2 RIGHT{1.0f,0.0f};
	 constexpr Vector2 UP{0.0f,-1.0f};
	 constexpr Vector2 DOWN{0.0f,1.0f};
	 constexpr std::string_view TITLE = "Snake";
}