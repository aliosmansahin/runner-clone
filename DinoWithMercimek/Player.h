#pragma once

struct Vec2 {
	float x, y;
};

class Player
{
public:
	Player();
	~Player();

public:
	void Update();
	void Draw();

private:
	Vec2 pos;
	Vec2 size;
};

