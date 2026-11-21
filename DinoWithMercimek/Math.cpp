#include "Math.h"

Vec2::Vec2()
{
	x = 0.0f;
	y = 0.0f;
}

Vec2::Vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vec2::Vec2(float v)
{
	x = v;
	y = v;
}

Vec2& Vec2::Clamp(float minX, float maxX, float minY, float maxY)
{
	if (x < minX)
		x = minX;
	else if (x > maxX)
		x = maxX;

	if (y < minY)
		y = minY;
	else if (y > maxY)
		y = maxY;

	return *this;
}

Vec2 Vec2::operator+(const Vec2& other)
{
	return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other)
{
	return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator-()
{
	return Vec2(-x, -y);
}

Vec2 Vec2::operator*(float v)
{
	return Vec2(x * v, y * v);
}

Vec2 Vec2::operator/(float v)
{
	return Vec2(x / v, y / v);
}

Vec2& Vec2::operator+=(const Vec2& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vec2& Vec2::operator-=(const Vec2& other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

Vec2& Vec2::operator*=(float v)
{
	x *= v;
	y *= v;

	return *this;
}

Vec2& Vec2::operator/=(float v)
{
	x /= v;
	y /= v;

	return *this;
}
