#include "Game.h"

void Game::Start()
{
    // Window settings
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Grand Theft Delay");
    SetTargetFPS(60);

    // Epic face
    player.SetSprite(LoadTexture("assets/epic_face.png"));
    player.SetPosition(screenWidth / 2, screenHeight / 2);
	
}

void Game::Update()
{

}

void Game::Render()
{
    player.Render();
}

bool Game::OnCollision(Collision first, Collision other)
{
	if (first.GetCanCollide() && other.GetCanCollide())
	{
		if (first.GetPosition().x < other.GetPosition().x + other.GetWidth() &&
			first.GetPosition().x + first.GetWidth() > other.GetPosition().x &&
			first.GetPosition().y < other.GetPosition().y + other.GetHeight() &&
			first.GetPosition().y + first.GetHeight() > other.GetPosition().y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
