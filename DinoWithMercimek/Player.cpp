#include "Player.h"

#include <raylib.h>

Player::Player()
{
	pos = { 0.0f, 0.0f };
	size = { 50.0f, 100.0f };
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Draw()
{
	DrawRectangle(pos.x, pos.y, size.x, size.y, WHITE);
}