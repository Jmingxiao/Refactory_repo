#pragma once

#include "Vector2.h"

struct Transform
{
	Transform() = default;
	Transform(float x, float y) noexcept;
	
	void SetPosition(const Vector2& position) noexcept;
	void ChangePosition(const Vector2& position) noexcept;

	Vector2 GetPosition() const noexcept;
	float GetX() const noexcept;
	float GetY() const noexcept;


private:
	Vector2 _position{};

};