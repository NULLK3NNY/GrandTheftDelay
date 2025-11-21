#pragma once
#include "raylib.h"

class Collision
{
public:
	Collision();
	void Enable();
	void Disable();
	int GetWidth();
	void SetWidth(int width);
	int GetHeight();
	void SetHeight(int height);
	Vector2 GetPosition();
	void UpdateCollisionV(Vector2 position);
	void UpdateCollision(float x, float y);
	void DrawBox();
	bool GetCanCollide();
private:
	Vector2 position{};
	int width{};
	int height{};
	bool canCollide{};
};