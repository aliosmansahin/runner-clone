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
