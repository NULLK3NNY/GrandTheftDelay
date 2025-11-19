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
	if (sprite.id != 0) 
	{
		Rectangle source = { 0, 0, 32, 32 };
		Rectangle dest = { position.x, position.y, 32, 32 };
		Vector2 origin = { 16, 16 };
		DrawTexturePro(sprite, source, dest, origin, rotation, WHITE);
	}
	else 
	{
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

void GameObject::SetRotation(float rotation)
{
	this->rotation = rotation;
}

Collision GameObject::GetCollider()
{
	return collision;
}
