#pragma once
#include "raylib.h"
#include "GameObject.h"
#include "Collision.h"
#include "Player.h"
#include "Debug.h"

class Game
{
public:
	~Game();
	void Start();
	void Update();
	void Render();
	// Collision
	void ProcessCollisions();
	bool OnCollision(Collision first, Collision other);
private:
	float deltaTime{};
	Player* player{};
	GameObject* testObject{};
	Debug* debug{};
};

