#include "Collision.h"

Collision::Collision()
{

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

void Collision::UpdateCollision(float x, float y)
{
	this->position.x = x - width / 2;
	this->position.y = y - width / 2;
}

void Collision::DrawBox()
{
	DrawRectangle(position.x, position.y, width, height, Color{ 255, 0, 0, 100 });
}

bool Collision::GetCanCollide()
{
	return canCollide;
}
