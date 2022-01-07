#pragma once

#include <iostream>
#include "Apple.h"
#include "RenderManager.h"


Apple::Apple(const Rectangle& r, const Color& c, const Transform& t) noexcept : rect(r),color(c),transform(t)
{
}

void Apple::Render(RenderManager& renderManager) {
	renderManager.Render(rect, color, transform);
}

void Apple::SetPosition(const Vector2& pos) noexcept
{
	transform.SetPosition(pos);
}

const Transform& Apple::Gettransform() const noexcept
{
	return transform;
}


