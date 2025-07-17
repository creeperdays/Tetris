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

/*
Initialises the screen
*/
void initScreen(); 

void drawScreen(); 

void drawTile(struct tile *t, int x, int y); 



#endif
