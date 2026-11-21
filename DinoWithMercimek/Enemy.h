#pragma once

#include "Math.h"

class Enemy
{
public:
	explicit Enemy(float startX);
	virtual ~Enemy() = default;

	void Update();
	virtual void Draw() = 0;
	
public:
	bool ShouldDespawn(float minX = 0.0f);

public:
	Vec2 GetMin();
	Vec2 GetMax();
	
protected:
	Vec2 pos;
	Vec2 size;

private:
	float speed = 300.0f;
};

