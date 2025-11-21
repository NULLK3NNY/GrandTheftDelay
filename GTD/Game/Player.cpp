#include "Player.h"

Player::Player()
{

}

void Player::OnFootMovement(float deltaTime)
{
	if (IsKeyDown(input.INPUT_UP))
	{
		MoveY(-speed, deltaTime);
	}
	if (IsKeyDown(input.INPUT_DOWN))
	{
		MoveY(speed, deltaTime);
	}
	if (IsKeyDown(input.INPUT_LEFT))
	{
		MoveX(-speed, deltaTime);
	}
	if (IsKeyDown(input.INPUT_RIGHT))
	{
		MoveX(speed, deltaTime);
	}
}

void Player::SetSpeed(float speed)
{
	this->speed = speed;
}
