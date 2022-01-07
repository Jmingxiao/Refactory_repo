#pragma once

#pragma once
#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning (disable:ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)

#include <vector>
#include "Color.h"
#include "Rectangle.h"
#include "Transform.h"


struct RenderManager
{
	struct RectEntry
	{
		const Rectangle rect;
		const Color color;
		const Transform transform;
	};

	void Render(const Rectangle& rect, const Color& color, const Transform& trans);
	void Rendering(SDL_Renderer* renderer) noexcept;
	void Clear() noexcept;

	std::vector<RectEntry> rectEntries;
};
