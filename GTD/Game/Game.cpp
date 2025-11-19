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
