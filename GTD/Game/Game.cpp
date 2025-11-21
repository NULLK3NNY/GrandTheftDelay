#include "Game.h"

Game::~Game()
{
	// Clean up
	delete(player);
	delete(playerCollider);
	delete(testCollider);
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
	player->SetWidth(32);
	player->SetHeight(32);
	player->SetSpeed(200.0f);
    player->SetSprite(LoadTexture("assets/epic_face.png"));
    player->SetPosition(screenWidth / 2, screenHeight / 2);
	// Create collision for player
	playerCollider = new Collision();
	playerCollider->SetWidth(32);
	playerCollider->SetHeight(32);

	// Create test collider
	testCollider = new Collision();
	testCollider->SetWidth(32);
	testCollider->SetHeight(32);
	testCollider->UpdateCollisionV(Vector2{ 200, 200 });
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
	playerCollider->DrawBox();
	testCollider->DrawBox();
}

void Game::ProcessCollisions()
{
	// Player collision
	playerCollider->UpdateCollision(player->GetPosition().x - player->GetWidth() / 2, player->GetPosition().y - player->GetHeight() / 2);

	// Check collision between two objects
	if (OnCollision(playerCollider, testCollider))
	{
		debug->PrintString("Collision Detected");
	}
}

bool Game::OnCollision(Collision* first, Collision* other)
{
	if (first->GetCanCollide() && other->GetCanCollide())
	{
		if (first->GetPosition().x < other->GetPosition().x + other->GetWidth() &&
			first->GetPosition().x + first->GetWidth() > other->GetPosition().x &&
			first->GetPosition().y < other->GetPosition().y + other->GetHeight() &&
			first->GetPosition().y + first->GetHeight() > other->GetPosition().y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
