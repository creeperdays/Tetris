#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "tile.h"

/*
This file will contain the main function execution for Tetris 
 */
int main(void) {
     // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Tetris");

    initScreen(); 

    printf("hello, world\n");

    drawTile(&t2, 3, 3); 
    setCurrentTile(&t2, 3, 3); 

    SetTargetFPS(10);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        if (IsKeyDown(KEY_RIGHT)) {
            shiftCurrentTileRight(); 
        }

        if (IsKeyDown(KEY_LEFT)) {
            shiftCurrentTileLeft(); 
        }

        if (IsKeyDown(KEY_DOWN)) {
            shiftCurrentTileDown(); 
        }

        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

        
            drawScreen(); 

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
