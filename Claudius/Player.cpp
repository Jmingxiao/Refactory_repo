#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>
#include <utility>
#include <algorithm>

const float Snake::movement_speed = 10.0f;
const float Snake::starting_x = 300.0f;
const float Snake::starting_y = 300.0f;
const std::vector<Vector2> Snake::move_dir = { Vector2(-1,0),Vector2(1,0),Vector2(0,-1),Vector2(0,1), Vector2(0,0)};


Snake::Snake() noexcept
{
	rect.SetBounds(0, 0, snakepart_size, snakepart_size);
	transform.SetPosition({ starting_x, starting_y });
	snakeparts = std::move(std::vector<SnakePart>(player_size, SnakePart(transform, Color::Blue(), rect)));
}
void Snake::Render(RenderManager& renderManager) 
{
	renderManager.Render(rect, color, transform);
	std::for_each(snakeparts.begin(), snakeparts.begin() + snake_length,
		[&](const auto& snakepart) {renderManager.Render(snakepart._rect, snakepart._color, snakepart._transform); });
}

void Snake::Update() noexcept
{
	const auto headdiff = transform.GetPosition() - snakeparts.front()._transform.GetPosition();
	const Vector2 speed(movement_speed, movement_speed);
	transform.ChangePosition(speed * move_dir.at(static_cast<size_t>(direction)));
	snakeparts.front()._transform.ChangePosition(headdiff);
	std::shift_right(snakeparts.begin(), snakeparts.end(), 1);

}


void Snake::OnKeyDown(KeyConfig::KeyCode key) noexcept
{
	using namespace KeyConfig;
	switch (key)
	{
	case KeyCode::LEFT_ARROW :
		direction = Direction::LEFT;
		break;
	case KeyCode::RIGHT_ARROW:
		direction = Direction::RIGHT;
		break;
	case KeyCode::UP_ARROW:
		direction = Direction::UP;
		break;
	case KeyCode::DOWN_ARROW:
		direction = Direction::DOWN;
		break;
	default: 
		direction = Direction::NONE;
		break;
	}
}

void Snake::ResetPlayer() noexcept
{
	snake_length = 0;
	direction = Direction::NONE;
	transform.SetPosition({ starting_x, starting_y });
}

void Snake::Score() noexcept
{
	if (snake_length < player_size) {
		snake_length++;
	}
}

int Snake::GetSnakeLength() const noexcept
{
	return snake_length;
}

bool Snake::CheckBodyCollision() const noexcept
{
	const auto bodycolliding = [&](const auto& snakepart)constexpr noexcept {return snakepart._transform.GetPosition() == transform.GetPosition(); };
	auto snakend = snakeparts.cbegin() + snake_length;
	return std::find_if(snakeparts.cbegin(), snakend, bodycolliding) != snakend;
}

bool Snake::CheckOutSideBound(const int width, const int height ) const noexcept
{
	return  transform.GetX() > width || transform.GetX() < 0 || transform.GetY() > height || transform.GetY() < 0;
}

const Transform& Snake::GetSnakeTransform() noexcept
{
	return transform;
}
