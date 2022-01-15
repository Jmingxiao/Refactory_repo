#include "Player.h"
#include <cmath>
#include "Renderer.h"
#include <iostream>
#include <utility>
#include <algorithm>


void Snake::Render(const Renderer& renderer) const noexcept
{
	for (auto part : snakeparts) {
		renderer.Render(part, Color::Green());
	}
}

void Snake::Update() noexcept
{
	const Vector2 speed(Config::SNAKE_SPEED,Config::SNAKE_SPEED);
	position += speed * direction;
	std::shift_right(snakeparts.begin(), snakeparts.end(), 1);
	snakeparts.front() = position;
}

void Snake::OnKeyDown(KeyCode key) noexcept
{
	switch (key)
	{
	case KeyCode::LEFT_ARROW:
		direction = Config::LEFT;
		break;
	case KeyCode::RIGHT_ARROW:
		direction = Config::RIGHT;
		break;
	case KeyCode::UP_ARROW:
		direction = Config::UP;
		break;
	case KeyCode::DOWN_ARROW:
		direction = Config::DOWN;
		break;
	default: 
		direction ={};
		break;
	}
}

void Snake::ResetPlayer() noexcept
{
	position = Config::SNAKE_STARTPOS;
	snakeparts.clear();
	Grow();
	direction = {};
	
}

void Snake::Grow() noexcept
{
	try {
			snakeparts.push_back(position);
	}
	catch (...) {
		//swallow the exception. The snake wont grow, but the game can keep running. 
	}
}

 bool Snake::CheckBodyCollision() const noexcept{
	return find(snakeparts.cbegin()+1,snakeparts.cend(),position) != snakeparts.cend();
}

bool Snake::CheckOutSideBound(const int width, const int height ) const noexcept
{
	return  position._x > width || position._x < 0 || position._y > height || position._y < 0;
}

Vector2 Snake::GetPosition() const noexcept
{
	return position;
}
