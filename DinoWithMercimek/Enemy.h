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

	bool IsCheckForScore() const { return checkedForScore; }

public:
	void SetCheckedForScore() { checkedForScore = true; }
	
protected:
	Vec2 pos;
	Vec2 size;

private:
	float speed = 300.0f;

private:
	bool checkedForScore = false;
};

