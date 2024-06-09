#include "include/raylib.h"
#include "game.h"

int main()
{
    Color darkBlue {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}