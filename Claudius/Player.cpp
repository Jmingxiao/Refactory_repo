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

void Snake::Initialize() noexcept
{
	color.SetColor(0, 255, 0, 0);
	rect.SetBounds(0, 0, snakepart_size, snakepart_size);
	transform.SetPosition({starting_x, starting_y});
	snake_length = 0;
	snakeparts = std::move(std::vector<SnakePart>(50, SnakePart(transform,Color(255,0,0,0),rect)));
	bodyDiff = std::move(std::vector<Vector2>(50));
	
}

void Snake::Render(RenderManager& renderManager)
{
	renderManager.Render(rect, color, transform);

	std::for_each(snakeparts.begin(), snakeparts.begin() + snake_length,
		[&](const auto& snakepart) {renderManager.Render(snakepart._rect, snakepart._color, snakepart._transform); });
}

void Snake::Update()
{
	bodyDiff.front() = transform.GetPosition() - snakeparts.front()._transform.GetPosition();


	for (size_t i = 1; i < snakeparts.size()-1; i++) 
	{
		bodyDiff.at(i) = snakeparts.at(i)._transform.GetPosition() - snakeparts.at(i+1)._transform.GetPosition();
	}

	const Vector2 speed(movement_speed, movement_speed);
	transform.ChangePosition(speed * move_dir.at(static_cast<size_t>(direction)));

	snakeparts.front()._transform.ChangePosition(bodyDiff.front());
	for (size_t i = 1; i < snakeparts.size(); i++)
	{
		snakeparts.at(i)._transform.ChangePosition(bodyDiff.at(i-1));
	}

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