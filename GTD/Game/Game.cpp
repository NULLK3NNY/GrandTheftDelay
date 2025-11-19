#include "Game.h"

void Game::Start()
{
    // Window settings
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Grand Theft Delay");
    SetTargetFPS(60);

    // Create player
	player = new Player();
	player->SetWidth(32);
	player->SetHeight(32);
	player->SetSpeed(200.0f);
    player->SetSprite(LoadTexture("assets/epic_face.png"));
    player->SetPosition(screenWidth / 2, screenHeight / 2);
	
}

void Game::Update()
{
	deltaTime = GetFrameTime();

	player->OnFootMovement(deltaTime);
}

void Game::Render()
{
    player->Render();
	player->GetCollider().DrawBox();
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
