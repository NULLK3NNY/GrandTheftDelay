#pragma once
#include "raylib.h"
#include "GameObject.h"

class Game
{
public:
	void Start();
	void Update();
	void Render();
private:
	GameObject player{};
};

