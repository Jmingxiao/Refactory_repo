#pragma once

#include "Vector2.h"

struct Transform
{
	Transform() = default;
	Transform(float x, float y, float rotation) noexcept;
	
	void SetPosition(const Vector2& position) noexcept;
	void ChangePosition(const Vector2& position) noexcept;
	void SetRotation(const float rotation) noexcept;
	void ChangeRotation(const float rotation) noexcept;

	Vector2 GetPosition() const noexcept;
	float GetX() const noexcept;
	float GetY() const noexcept;
	constexpr float GetRotation() const noexcept;

private:
	Vector2 _position{};
	float _rotation{};
};