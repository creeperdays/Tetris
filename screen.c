#include <stdlib.h>
#include "raylib.h"
#include "screen.h"


// The size of the screen
int screen[SCREEN_HEIGHT][SCREEN_WIDTH]; 


/*
 * This function initialises all screen space to zeros
 * This means that the screen will be fully blank at the start
 */
void initScreen() {
    int i; 
    int j; 

    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            screen[i][j] = 0; 
        }
    }
}


/*
This function draws the screen so that it can be viewed by the player 
in the play window. These are going to be 10 by 10 squares which appear in the middle of the screen 
*/
void drawScreen() {
    int i; 
    int j; 

    // Calculate the middle of the screen 
    int mid = WINDOW_WIDTH/2; 

    int start = mid - (SCREEN_WIDTH/2)*SQUARE_WIDTH; 

    int height = WINDOW_HEIGHT - 5*SQUARE_WIDTH; 

    for (i = 0; i < SCREEN_HEIGHT - 5; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            int x = start + j * SQUARE_WIDTH;
            int d = SQUARE_WIDTH; 
            if (screen[i][j] == 1) {
                DrawRectangle(x, height, d, d, BLACK); 
            } else if (screen[i][j] == 0) {
                DrawRectangleLines(x, height, d, d, BLACK); 
            }
        }

        height -= SQUARE_WIDTH; 
    }

}

