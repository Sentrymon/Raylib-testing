#include "raylib.h"
#include <thread>

#define NUM_TEXTURES 1

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int celluarTileSize = 16;


    InitWindow(screenWidth, screenHeight, "raylib celluar text");

    //load images etc.
    Image cellular = GenImageCellular(screenWidth, screenHeight, celluarTileSize); //generate an image with the celluar math function with the tile size of 32

    Texture2D texture = LoadTextureFromImage(cellular);


    UnloadImage(cellular);

    int currentTexture = 0;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawTexture(texture, 0, 0, Color{255,255,255,255});

        EndDrawing();
    }

    UnloadTexture(texture);

    CloseWindow();        // Close window and OpenGL context
    return 0;
}
