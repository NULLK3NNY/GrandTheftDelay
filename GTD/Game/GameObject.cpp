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
		source = { 0, 0, (float)width, (float)height };
		dest = { position.x, position.y, (float)width, (float)height };
		origin = { (float)width / 2, (float)height / 2 };
		DrawTexturePro(sprite, source, dest, origin, rotation, WHITE);
	}
	else 
	{
		DrawRectangle(position.x, position.y, width, height, WHITE);
	}
}

void GameObject::SetSprite(Texture2D sprite)
{
	this->sprite = sprite;
}

Vector2 GameObject::GetPosition()
{
	return position;
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

int GameObject::GetWidth()
{
	return width;
}

void GameObject::SetWidth(int width)
{
	this->width = width;
}

int GameObject::GetHeight()
{
	return height;
}

void GameObject::SetHeight(int height)
{
	this->height = height;
}

void GameObject::MoveX(float speed, float deltaTime)
{
	position.x += speed * deltaTime;
}

void GameObject::MoveY(float speed, float deltaTime)
{
	position.y += speed * deltaTime;
}

void GameObject::UpdateCollision()
{
	collider.UpdateCollisionV(position);
}
