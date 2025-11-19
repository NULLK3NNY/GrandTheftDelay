#include "Collision.h"

Collision::Collision()
{
	Enable();
}

void Collision::Enable()
{
	canCollide = true;
}

void Collision::Disable()
{
	canCollide = false;
}

void Collision::SetWidth(int width)
{
	this->width = width;
}

void Collision::SetHeight(int height)
{
	this->height = height;
}

int Collision::GetWidth()
{
	return width;
}

int Collision::GetHeight()
{
	return height;
}

Vector2 Collision::GetPosition()
{
	return position;
}

void Collision::UpdateCollision(Vector2 position)
{
	this->position = position;
}

void Collision::DrawBox()
{
	DrawRectangle(position.x, position.y, width, height, Color{ 255, 0, 0, 100 });
}

bool Collision::GetCanCollide()
{
	return canCollide;
}

void Collision::SetCanCollide(bool value)
{
	this->canCollide = value;
}
