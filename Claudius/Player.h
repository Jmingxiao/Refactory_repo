#pragma once		// #pragma once == Compile this file once.

#include "Color.h"
#include "Rectangle.h"
#include "KeyCode.h"
#include "Vector2.h"
#include <vector>
#include "ConstValue.h"

struct RenderManager;


struct Snake
{
private:
	using SnakeParts = Vector2;

	Rectangle rect{ 0, 0, Consts::snakeDefautsize, Consts::snakeDefautsize };
	Color color{Color::Green()};
	Vector2 direction{};
	Vector2 transform{300.0f,300.0f};
	std::vector<SnakeParts> snakeparts = {Vector2()};

public:
	void OnKeyDown(KeyCode key) noexcept;
	void Render(RenderManager& renderManager);				
	void Update() noexcept ;
	void ResetPlayer() noexcept;
	void Score() noexcept;
	bool CheckBodyCollision() const noexcept;
	bool CheckOutSideBound(const int width, const int height) const noexcept;
	const Vector2& Gettransform() const noexcept;

};