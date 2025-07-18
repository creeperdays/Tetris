#include "tile.h"
#ifndef SCREEN_H 
#define SCREEN_H 

//The width and the height of the game board
#define SCREEN_WIDTH 10 
#define SCREEN_HEIGHT 25

// The width of the squares 
#define SQUARE_WIDTH 30; 

// The height and width of the window (the game window created in openGL)
#define WINDOW_HEIGHT 800 
#define WINDOW_WIDTH 500

/*
This header file defines the functions related to the screen display of Tetris 
*/

extern int screen[SCREEN_HEIGHT][SCREEN_WIDTH];

extern int currentTile[4][4]; 

extern int currentTileWidth; 

extern int currentTileLength; 

extern int currentTilePosX; 

extern int currentTilePosY; 

/*
Initialises the screen
*/
void initScreen(); 

/**
 * Draws the screen on to the window
 */
void drawScreen(); 


/**
 * Draws the tile on to the screen 
 */

void drawTile(struct tile *t, int x, int y); 

/**
 * Sets the current tile to be the new tile
 */
void setCurrentTile(struct tile *t, int x, int y); 

/**
 * This function clears the current tile off the screen
 */
void clearCurrentTile(); 

/**
 * This function draws the current tile on the screen  
 * This function only uses global variables as its input
 */
void drawCurrentTile(); 

/**
 * This function shifts the current tile to the right
 */
void shiftCurrentTileRight(); 

/**
 * This function shifts the current tile to the left
 */

void shiftCurrentTileLeft(); 


/**
 * This function shifts the current tile down 
 */
void shiftCurrentTileDown(); 

/**
 * This function will rotate the current tile
 * Then once the current tile has been rotated then it also 
 * draws this new current tile onto the screen
 */
void rotateCurrentTile(); 



#endif
