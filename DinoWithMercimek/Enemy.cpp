#include "Enemy.h"

#include <raylib.h>

Enemy::Enemy(float startX)
{
	this->pos.x = startX;
}

void Enemy::Update()
{
	pos.x -= speed * GetFrameTime();
}

bool Enemy::ShouldDespawn(float minX)
{
	return pos.x < minX - size.x - 10.0f;
}
