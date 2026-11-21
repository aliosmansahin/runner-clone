#pragma once

#include "Math.h"

class Player
{
public:
	Player(float maxY);
	~Player();

public:
	void Update();
	void Draw();

public:
	Vec2 GetMin();
	Vec2 GetMax();

private:
	void UpdatePosition();
	void HandleKeyInput();

private:
	Vec2 pos;
	Vec2 size;
	Vec2 vel;
	Vec2 gravity;

	float maxY;
	Vec2 jump;
	bool isGrounded;
};

