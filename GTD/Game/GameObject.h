#pragma once
#include "raylib.h"
#include "Collision.h"
#include "Debug.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	void Render();
	void SetSprite(Texture2D sprite);
	void SetPositionV(Vector2 position);
	void SetPosition(float x, float y);
	void SetRotation(float rotation);
private:
	Vector2 position{};
	float rotation{};
	Texture2D sprite{};
	Collision collision{};
};

