#include "raylib.h"


int main()
{
    InitWindow(800, 450, "My First Window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}