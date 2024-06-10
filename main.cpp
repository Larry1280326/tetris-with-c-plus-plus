#include "include/raylib.h"
#include "game.h"
#include "color.h"
#include "iostream"

double lastUpdateTime{0};
bool EventTriggered(double interval = 0.2)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);
    double interval = 0.2;

    Font font = LoadFontEx("font/monogram.ttf", 64, 0, 0);

    Game game;

    while(!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(interval)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 30, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 30, 2, WHITE);
        if (game.gameOver) DrawTextEx(font, "GAME OVER", {320, 450}, 30, 2, WHITE);
        DrawRectangleRounded({320, 55, 170, 68}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        
        DrawTextEx(font, scoreText, {320+ (170 - textSize.x)/2, 65}, 38, 2, WHITE);

        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}