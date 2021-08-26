#include "raylib.h"
#include <unistd.h>
#include <chrono>
#include <string>
#include <iostream>
#include <thread>

#include "randomFuckingFunctions.cpp"

using namespace std::chrono_literals;

#define NUM_TEXTURES 1

//To convert from Float to const char * use this  
//sprintf(charBuffer, "%.*g", FLT_DECIMAL_DIG-1, input);


int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    std::chrono::seconds sec(1);
    char charBuffer[FLT_STRING_SIZE];

    InitWindow(screenWidth, screenHeight, "Game Window");

    Vector2 playerPos = {static_cast<float>(screenWidth/2), static_cast<float>(screenHeight/2)};
    Vector2 playerPosOffset = {20.0f, 20.0f};
    Color BallColour = DARKBLUE;

    Rectangle poggers = {300.0f, 200.0f, 40.0f, 40.0f};

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        //Change ball color
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){BallColour = RED;}
        else if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)){BallColour = BLUE;};
        //Manage keyboard input
        if(IsKeyDown(KEY_W)) playerPos.y -= 6.0f;
        if(IsKeyDown(KEY_A)) playerPos.x -= 6.0f;
        if(IsKeyDown(KEY_S)) playerPos.y += 6.0f;
        if(IsKeyDown(KEY_D)) playerPos.x += 6.0f;
        Vector2 playerCenterPos = Vector2Add(playerPos, playerPosOffset);


        //Camera management
        Camera2D camera = { 0 };
        camera.target = {playerCenterPos};
        camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f};
        camera.rotation = 0.0f;
        camera.zoom = 1.0f;

        /*
        Move camera
        for (int i=0; i<=100; i++)
        {
            Vector2 cameraLerp = camera.target;
            camera.target = Vector2Lerp(cameraLerp, playerCenterPos, static_cast<float>(i/100));

            std::this_thread::sleep_for(20ms);
        }
        */
       
       camera.target = playerCenterPos;
        

        
        //Debug
        sprintf(charBuffer, "%.*g", FLT_DECIMAL_DIG-1, playerPos.x);
        DrawText(charBuffer, 640, 10, 20, RED);
        sprintf(charBuffer, "%.*g", FLT_DECIMAL_DIG-1, playerPos.y);
        DrawText(charBuffer, 640, 35, 20, RED);
        sprintf(charBuffer, "%.*g", FLT_DECIMAL_DIG-1, GetFrameTime());
        DrawText(charBuffer, 640, 60, 20, RED);
        std::string s = "FPS:"+std::to_string(GetFPS());
        DrawText(s.c_str(), 640, 85, 20, RED);

        
        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode2D(camera);

                DrawCircleV(playerPos, 40, BallColour);
                DrawRectangleRec(poggers, BLACK);

            EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
