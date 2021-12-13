#pragma once

struct Vector2
{
	float x {}; 
	float y {};

	Vector2() = default;
	Vector2(const float x, const float y) noexcept;

	Vector2 operator+(const Vector2& rhs) const noexcept;
	Vector2 operator-(const Vector2& rhs) const noexcept;
	Vector2 operator*(const Vector2& rhs) const noexcept;
	Vector2 operator/(const Vector2& rhs) const noexcept;
	Vector2 operator*(const float rhs) const noexcept;
	Vector2 operator/(const float rhs) const noexcept;

	bool operator==(const Vector2& rhs) const noexcept;

	Vector2 perpendicular() const noexcept;
	Vector2 unit() const noexcept;

	float length() const noexcept;
	float length_squared() const noexcept;
	float dot(const Vector2& rhs) const noexcept;
	float cross(const Vector2& rhs) const noexcept;
	void normalize() noexcept ;

};