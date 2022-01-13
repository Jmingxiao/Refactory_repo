#pragma once
#include <string>
#include "Vector2.h"
namespace Consts {
	 constexpr unsigned int FrameRate = 50u;
	 constexpr int SCR_Width = 1000;
	 constexpr int SCR_Height = 700;
	 constexpr unsigned int appleSize = 10;
	 constexpr float snakeSpeed = 10.0f;
	 constexpr float snakepartoffset = 1.0f;
	 constexpr unsigned int snakeDefautsize = 10;
	 constexpr unsigned int snakeMaxLength = 50;
	 constexpr Color appleColor{ Color::Red() };
	 constexpr Vector2 startposition{300,300};
	 constexpr Vector2 Left{-1.0f,0.0f};
	 constexpr Vector2 Right{1.0f,0.0f};
	 constexpr Vector2 Up{0.0f,-1.0f};
	 constexpr Vector2 Down{0.0f,1.0f};
	 const std::string title = "Snake";

}