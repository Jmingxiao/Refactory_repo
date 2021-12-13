#pragma once

#include "KeyCode.h"
#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"

//<- Kinda like #include "RenderManager.h", not exactly. Can't use functions. Google forward declaration.

struct Apple
{

	Apple() = default;
	void Render(struct RenderManager& renderManager);
	void Initialize(int width, int height) noexcept;

	Collider rect{};
	Color color{};
	Transform trans{};

	bool new_apple = false;
};