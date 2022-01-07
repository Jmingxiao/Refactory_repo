#include "Transform.h"




Transform::Transform(float x, float y) noexcept: _position(x,y)
{
}

void Transform::SetPosition(const Vector2& position) noexcept
{
	_position = position;
}

void Transform::ChangePosition(const Vector2& position) noexcept
{
	_position = _position+position;
}


Vector2 Transform::GetPosition() const noexcept
{
	return _position;
}

float Transform::GetX() const noexcept
{
	return _position.x;
}

float Transform::GetY() const noexcept
{
	return _position.y;
}


