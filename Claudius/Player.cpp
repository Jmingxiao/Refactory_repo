#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>
#include <utility>
#include <algorithm>


void Snake::Render(RenderManager& renderManager) 
{
	renderManager.Render(rect, color, transform);
	for (auto part : snakeparts) {
		renderManager.Render(rect, color, part);
	}
}

void Snake::Update() noexcept
{
	const auto headdiff = transform - snakeparts.front();
	const Vector2 speed(Consts::snakeSpeed,Consts::snakeSpeed);
	transform += speed * direction;
	snakeparts.front() += headdiff ;
	std::shift_right(snakeparts.begin(), snakeparts.end(), 1);
}

void Snake::OnKeyDown(KeyCode key) noexcept
{
	switch (key)
	{
	case KeyCode::LEFT_ARROW:
		direction = Consts::Left;
		break;
	case KeyCode::RIGHT_ARROW:
		direction = Consts::Right;
		break;
	case KeyCode::UP_ARROW:
		direction = Consts::Up;
		break;
	case KeyCode::DOWN_ARROW:
		direction = Consts::Down;
		break;
	default: 
		direction ={};
		break;
	}
}

void Snake::ResetPlayer() noexcept
{
	snakeparts.clear();
	snakeparts.push_back(transform);
	direction = {};
	transform = Consts::startposition;
}

void Snake::Score() noexcept
{
	if (snakeparts.size() < Consts::snakeMaxLength) {
		snakeparts.push_back(transform+direction*Consts::snakepartoffset);
	}
}

 bool Snake::CheckBodyCollision() const noexcept
{
	return find(snakeparts.cbegin(),snakeparts.cend(),transform)!=snakeparts.cend();
}

bool Snake::CheckOutSideBound(const int width, const int height ) const noexcept
{
	return  transform.x > width || transform.x < 0 || transform.y > height || transform.y < 0;
}

const Vector2& Snake::Gettransform() const noexcept
{
	return transform;
}
