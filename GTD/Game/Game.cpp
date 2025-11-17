#include "Game.h"

void Game::Start()
{
    // Window settings
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Grand Theft Delay");
    SetTargetFPS(60);

    // Epic face
    epicFace.SetSprite(LoadTexture("assets/epic_face.png"));
    epicFace.SetPosition(screenWidth / 2, screenHeight / 2);
}

void Game::Update()
{
    float deltaTime = GetFrameTime();

    x += 1 * deltaTime;
    epicFace.SetPosition(x, 0);

}

void Game::Render()
{
    epicFace.Render();
}
