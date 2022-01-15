#include "Vector2.h"
#include <cmath>

Vector2 Vector2::operator+(const Vector2& rhs) const noexcept
{
	return Vector2(_x + rhs._x, _y + rhs._y);
}

Vector2 Vector2::operator-(const Vector2& rhs) const noexcept
{
	return Vector2(_x - rhs._x, _y - rhs._y);
}

Vector2 Vector2::operator*(const Vector2& rhs) const noexcept
{
	return Vector2(_x * rhs._x, _y * rhs._y);
}

Vector2 Vector2::operator/(const Vector2& rhs) const noexcept
{
	return Vector2(_x / rhs._x, _y / rhs._y);
}

Vector2& Vector2::operator+=(const Vector2& rhs)  noexcept
{
	this->_x += rhs._x;
	this->_y += rhs._y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)  noexcept
{
	this->_x += rhs._x;
	this->_y += rhs._y;
	return *this;
}

Vector2 Vector2::operator*(const float rhs) const noexcept
{
	return Vector2(_x * rhs, _y * rhs);
}

Vector2 Vector2::operator/(const float rhs) const noexcept
{
	return Vector2(_x / rhs, _y / rhs);
}

bool Vector2::operator==(const Vector2& rhs) const noexcept
{
	return (this->_x == rhs._x && this->_y == rhs._y);
}

Vector2 Vector2::perpendicular() const noexcept
{
	return Vector2(-_y, _x); // 90 degrees to the right
}

Vector2 Vector2::unit() const noexcept
{
	Vector2 result(*this); 
	result.normalize(); 
	return result;
}

float Vector2::length() const noexcept
{
	return sqrtf(_x * _x + _y * _y);
}

float Vector2::length_squared() const noexcept
{
	return _x * _x + _y * _y;
}

float Vector2::dot(const Vector2& rhs) const noexcept
{
	return _x * rhs._x + _y * rhs._y;
}

float Vector2::cross(const Vector2& rhs) const noexcept
{
	return _x * rhs._y - _y * rhs._x;
}

void Vector2::normalize() noexcept
{
	const float len = length(); 
	_x /= len; 
	_y /= len;
}
