#pragma once
#include "raylib.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	void Render();
	void SetSprite(Texture2D sprite);
	void SetPositionV(Vector2 position);
	void SetPosition(float x, float y);
private:
	Vector2 position{};
	Texture2D sprite{};
};

