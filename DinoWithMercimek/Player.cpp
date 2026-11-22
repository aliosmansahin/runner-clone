#include "Player.h"

#include <raylib.h>

Player::Player(float maxY)
{
	size = Vec2(50.0f, 100.0f);
	pos = Vec2(100.0f, maxY - size.y);
	jump = Vec2(0.0f, 500.0f);

	vel = 0.0f;
	gravity = Vec2(0.0f, 1000.0f);

	this->maxY = maxY;
	this->isGrounded = true;
	this->maxDiffYToBufferJump = 50.0f;
	this->jumpBuffered = false;
	this->performJump = false;
}

Player::~Player()
{
}

void Player::Update()
{
	HandleKeyInput();
	UpdatePosition();
}

void Player::Draw()
{
	DrawRectangle(pos.x, pos.y, size.x, size.y, WHITE);
}

Vec2 Player::GetMin()
{
	return pos;
}

Vec2 Player::GetMax()
{
	return (pos + size);
}

void Player::UpdatePosition()
{
	vel += gravity * GetFrameTime();

	vel.Clamp(0.0f, 0.0f, -500.0f, 500.0f);

	pos += vel * GetFrameTime();

	if (pos.y + size.y > maxY) {
		pos.y = maxY - size.y;
		vel = 0.0f;
		isGrounded = true;
		if (jumpBuffered) {
			performJump = true;
			jumpBuffered = false;
		}
	}
}

void Player::HandleKeyInput()
{
	if (performJump || IsKeyPressed(KEY_SPACE)) {
		if (isGrounded) {
			vel = -jump;
			isGrounded = false;
		}
		else {
			int diffY = maxY - (pos.y + size.y);

			if (diffY < maxDiffYToBufferJump) {
				jumpBuffered = true;
			}
		}
		performJump = false;
	}
}
