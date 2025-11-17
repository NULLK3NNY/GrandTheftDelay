#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{
	UnloadTexture(sprite);
}

void GameObject::Render()
{
	if (sprite.id != 0) {
		DrawTexture(sprite, position.x, position.y, WHITE);
	}
	else {
		DrawRectangle(position.x, position.y, 32, 32, WHITE);
	}
}

void GameObject::SetSprite(Texture2D sprite)
{
	this->sprite = sprite;
}

void GameObject::SetPositionV(Vector2 position)
{
	this->position = position;
}

void GameObject::SetPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}
