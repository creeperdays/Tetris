#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "screen.h"
#include "tile.h"


// The size of the screen
int screen[SCREEN_HEIGHT][SCREEN_WIDTH]; 

int currentTile[4][4]; 

int currentTileWidth; 

int currentTileLength; 

int currentTilePosX; 

int currentTilePosY; 


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

    int height = WINDOW_HEIGHT - 2*SQUARE_WIDTH; 

    for (i = SCREEN_HEIGHT - 1; i >= 0; i--) {
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




void drawTile(struct tile *t, int x, int y) {
    int posX = x; 
    int posY = y; 

    int i; 
    int j; 

    for (i = 0; i < t->length; i++) {
        for (j = 0; j < t->width; j++) {
            screen[posY + i][posX + j] = t->container[i][j];  
        }
    }

}

void setCurrentTile(struct tile *t, int x, int y) {
    currentTileWidth = t->width; 
    currentTileLength = t->length; 

    int i; 
    int j; 
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            currentTile[i][j] = t->container[i][j]; 
        }
    }

    currentTilePosX = x; 
    currentTilePosY = y; 
}

void clearCurrentTile() {
    int i; 

    int j; 

    for (i = 0; i < currentTileLength; i++) {
        for (j = 0; j < currentTileWidth; j++) {
            if (currentTile[i][j] == 1) {
                screen[currentTilePosY + i][currentTilePosX + j] = 0; 
            }
        }
    }
}

void drawCurrentTile() { 
    int i; 
    int j; 

    for (i = 0; i < currentTileLength; i++) {
        for (j = 0; j < currentTileWidth; j++) {
            if (currentTile[i][j] == 1) {
                screen[currentTilePosY + i][currentTilePosX +j] = 1; 
            }
        }
    }
}


void shiftCurrentTileRight() {
    if (currentTilePosX + currentTileWidth < SCREEN_WIDTH) {
        clearCurrentTile(); 
        currentTilePosX++; 
        drawCurrentTile(); 
    }
}

void shiftCurrentTileLeft() {
    if (currentTilePosX - 1 >= 0) {
        clearCurrentTile(); 
        currentTilePosX--; 
        drawCurrentTile(); 
    }
}

void shiftCurrentTileDown() {
    if (currentTilePosY + currentTileLength < SCREEN_HEIGHT) {
        clearCurrentTile(); 
        currentTilePosY++; 
        drawCurrentTile(); 
    }
}



void rotateCurrentTile() {
    clearCurrentTile();
    // To rotate a tile clockwise we must transpose the tile matrix then reverse the rows

    //first transpose the tile matrix 
    int i; 
    int j; 

    int temp = currentTileLength; 
    int temp1 = currentTileWidth; 
    
    int temp2; 

    for (i = 0; i < 4; i++) {
        for (j = i+1; j < 4; j++) {
            temp2 = currentTile[j][i]; 
            currentTile[j][i] = currentTile[i][j];
            currentTile[i][j] = temp2;  
            
        }
    }

    printCurrentTile(); 

    //The new matrix has switched dimensions 
    currentTileLength = temp1; 
    currentTileWidth = temp; 

    //Then we can reverse the rows of the matrix 

    for (i = 0; i < currentTileLength; i++) {
        int low = 0; 
        int high = currentTileWidth - 1; 

        while (low < high) {
            int temp3 = currentTile[i][low]; 
            currentTile[i][low] = currentTile[i][high]; 
            currentTile[i][high] = temp3; 

            low++; 
            high--; 
        }
    }

     
    drawCurrentTile(); 
}

void printCurrentTile() {
    int i; 
    int j; 

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", currentTile[i][j]); 
        }
        printf("\n"); 
    }

    printf("\n"); 
}



