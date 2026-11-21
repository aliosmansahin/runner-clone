#include "Cactus.h"

#include <raylib.h>

Cactus::Cactus(float startX, float groundY) : Enemy(startX)
{
	size = Vec2(50.0f, 75.0f);
	pos.y = groundY - size.y;
}

Cactus::~Cactus()
{}

void Cactus::Draw()
{
	DrawRectangle(pos.x, pos.y, size.x, size.y, WHITE);
}
