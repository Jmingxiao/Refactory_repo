#pragma once		// #pragma once == Compile this file once.

#include "Color.h"
#include "Rectangle.h"
#include "KeyCode.h"
#include "Vector2.h"
#include <vector>
#include "ConstValue.h"

class Renderer;

class Snake
{
private:
	using SnakeParts = Vector2;

	Rectangle rect{ 0, 0, Config::SNAKE_UNIT_SIZE, Config::SNAKE_UNIT_SIZE };
	Vector2 direction{};
	Vector2 position{300.0f,300.0f};
	std::vector<SnakeParts> snakeparts = {position};

public:
	void OnKeyDown(KeyCode key) noexcept;
	void Render(const Renderer& renderManager) const noexcept;				
	void Update() noexcept ;
	void ResetPlayer() noexcept;
	void Grow() noexcept;
	bool CheckBodyCollision() const noexcept;
	bool CheckOutSideBound(const int width, const int height) const noexcept;
	Vector2 GetPosition() const noexcept;
};