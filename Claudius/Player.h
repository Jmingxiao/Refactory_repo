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
	
	Transform transform{};
	Color color{};
	Rectangle rect;
	std::vector<SnakePart> snakeparts{};
	std::vector<Vector2> bodyDiff{};
	Direction direction{};

	Snake() = default;
	void OnKeyDown( KeyConfig::KeyCode key) noexcept;
	void Initialize() noexcept;
	void Render(RenderManager& renderManager);				// A reference or pointer doesn't need to be #include, just a forward declare.
	void Update() ;
	void ResetPlayer() noexcept;

	
	

	int snake_length = 0;


};