#include "Transform.h"




Transform::Transform(float x, float y, float rotation) noexcept: _position(x,y), _rotation(rotation)
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

void Transform::SetRotation(const float rotation) noexcept
{
	_rotation = rotation;
}

void Transform::ChangeRotation(const float rotation) noexcept
{
	_rotation += rotation;
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

constexpr float Transform::GetRotation() const noexcept
{
	return _rotation;
}
