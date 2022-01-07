#pragma once		// #pragma once == Compile this file once.

#include "Transform.h"
#include "Color.h"
#include "Rectangle.h"
#include "KeyCode.h"
#include <vector>

struct RenderManager;

struct Snake
{

	static const int snakepart_size = 10;
	static const int player_size = 50;
	static const float starting_x;
	static const float starting_y;
	static const float movement_speed;
	static const std::vector<Vector2> move_dir;

private:
	struct SnakePart
	{
		SnakePart() = default;
		SnakePart(Transform transform, Color color, Rectangle rect) noexcept :_transform(transform),_color(color),_rect(rect){}
		Transform _transform;
		Color _color;
		Rectangle _rect;
	};

	enum class Direction
	{
		LEFT = 0,RIGHT = 1,UP = 2,DOWN = 3, NONE = 4
	};


	Color color{Color::Green()};
	Rectangle rect;
	int snake_length{};
	Transform transform{};
	std::vector<Vector2> bodyDiff{};
	std::vector<SnakePart> snakeparts{};
	Direction direction{Direction::NONE};

public:


	Snake()noexcept;
	void OnKeyDown( KeyConfig::KeyCode key) noexcept;
	void Render(RenderManager& renderManager);				
	void Update() noexcept ;
	void ResetPlayer() noexcept;
	void Score() noexcept;
	int GetSnakeLength() const noexcept;
	bool CheckBodyCollision() const noexcept;
	bool CheckOutSideBound(const int width, const int height) const noexcept;
	const Transform& GetSnakeTransform() noexcept;

};