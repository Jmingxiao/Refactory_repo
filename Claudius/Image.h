#pragma once

struct Image
{
private:
	unsigned int _id;
	int _width;
	int _height;
	
public:
	Image() = default;
	Image(unsigned int id, int width, int height) noexcept;

	
	const void SetID(const unsigned int id) noexcept;
	constexpr void SetWidth(const int width) noexcept;
	constexpr void SetHeight(const int height) noexcept;

	const unsigned int GetID() const noexcept;
	const int GetWidth() const noexcept;
	const int GetHeight() const noexcept;
};