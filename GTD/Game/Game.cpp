#include "Game.h"

Game::~Game()
{
	// Clean up
	delete(player);
	delete(debug);
}

void Game::Start()
{
    // Window settings
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Grand Theft Delay");
    SetTargetFPS(60);

	// Create debug
	debug = new Debug();

    // Create player
	player = new Player();
	player->SetWidth(64);
	player->SetHeight(64);
	player->SetSpeed(200.0f);
    player->SetSprite(LoadTexture("assets/epic_face.png"));
    player->SetPosition(screenWidth / 2, screenHeight / 2);
	// Give player a collision box
	player->SetupCollisionBox(player->GetWidth(), player->GetHeight());
	player->GetCollision().Enable();

	// Create a test object
	testObject = new GameObject();
	testObject->SetWidth(100);
	testObject->SetHeight(100);
	testObject->SetupCollisionBox(testObject->GetWidth(), testObject->GetHeight());
	testObject->GetCollision().Enable();
}

void Game::Update()
{
	deltaTime = GetFrameTime();
	player->OnFootMovement(deltaTime);

	ProcessCollisions();
}

void Game::Render()
{
    player->Render();
	player->GetCollision().DrawBox();
	testObject->GetCollision().DrawBox();
}

void Game::ProcessCollisions()
{
	player->UpdateCollision();
	testObject->UpdateCollision();

	if (OnCollision(player->GetCollision(), testObject->GetCollision()))
	{
		debug->PrintString("Collision Detected");
	}
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
