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
	int GetWidth();
	void SetWidth(int width);
	int GetHeight();
	void SetHeight(int height);
	void MoveX(float speed, float deltaTime);
	void MoveY(float speed, float deltaTime);
	void SetupCollision();
	void UpdateCollision();
private:
	Vector2 position{};
	float rotation{};
	int width{};
	int height{};
	Rectangle source{};
	Rectangle dest{};
	Vector2 origin{};
	Texture2D sprite{};
	Collision collider{};
};

