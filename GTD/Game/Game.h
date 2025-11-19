#pragma once
#include "raylib.h"
#include "GameObject.h"
#include "Collision.h"
#include "Player.h"

class Game
{
public:
	void Start();
	void Update();
	void Render();
	bool OnCollision(Collision first, Collision other);
private:
	float deltaTime{};
	Player* player{};
};

