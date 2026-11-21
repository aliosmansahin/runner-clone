#pragma once

class Vec2 {
public:
	Vec2();
	Vec2(float x, float y);
	Vec2(float v);

public:
	Vec2& Clamp(float minX, float maxX, float minY, float maxY);

public:
	Vec2 operator+(const Vec2& other);
	Vec2 operator-(const Vec2& other);
	Vec2 operator-();
	Vec2 operator*(float v);
	Vec2 operator/(float v);
	Vec2& operator+=(const Vec2& other);
	Vec2& operator-=(const Vec2& other);
	Vec2& operator*=(float v);
	Vec2& operator/=(float v);

public:
	float x, y;
};
