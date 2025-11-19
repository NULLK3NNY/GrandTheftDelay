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
	Vector2 GetPosition();
	void SetPositionV(Vector2 position);
	void SetPosition(float x, float y);
	void SetRotation(float rotation);
	void SetWidth(int width);
	void SetHeight(int height);
	Collision GetCollider();
	void MoveX(float speed, float deltaTime);
	void MoveY(float speed, float deltaTime);
private:
	Vector2 position{};
	float rotation{};
	int width{};
	int height{};
	Rectangle source{};
	Rectangle dest{};
	Vector2 origin{};
	Texture2D sprite{};
	Collision collision{};
};

