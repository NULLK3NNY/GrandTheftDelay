#pragma once
#include "GameObject.h"
#include "Input.h"

class Player : public GameObject
{
public:
	Player();
	void OnFootMovement(float deltaTime);
	void SetSpeed(float speed);
private:
	Input input{};
	float speed{};
};

