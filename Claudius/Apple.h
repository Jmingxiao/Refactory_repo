#pragma once

#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"

struct RenderManager;

class Apple
{
public:
	bool new_apple = false;

	Apple() = default;
	Apple(const Rectangle& r, const Color& c, const Transform& t) noexcept;
	void Render( RenderManager& renderManager);
	void SetPosition(const Vector2&) noexcept;
	const Transform& Gettransform()const noexcept;

private:
	Rectangle rect{0,0,10,10};
	Color color{Color::Red()};
	Transform transform{100,100};
};