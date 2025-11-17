#include "Game.h"

int main(void)
{
    Game* game = new Game();

    game->Start();

    while (!WindowShouldClose())
    {
        game->Update();

        BeginDrawing();

        ClearBackground(BLACK);

        game->Render();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}