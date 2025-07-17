#ifndef TILE_H 
#define TILE_H

/**
 * This defines all the operations relating to tiles in the game of tetris
 */

struct tile {
    int container[4][4]; 
    int width; 
    int length; 
}; 

// This tile stores the 1 by 4 tile
extern struct tile t1; 

// This tile stores the 2 by 2 tile 
extern struct tile t2; 

// This tile stores the S tile
extern struct tile t3; 

// This tile stores the Z tile
extern struct tile t4; 

// This tile stores the L tile
extern struct tile t5; 

// This tile stores the J tile
extern struct tile t6; 

// This tile stores the T tile
extern struct tile t7; 








#endif
