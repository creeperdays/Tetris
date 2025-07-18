#include "tile.h"
#include <stdlib.h>

/*
This source file describes all the shape of the tiles within the tetris game and stores them in memory
*/

// The 1 by 4 tile  

struct tile t1 = {{{1, 0, 0, 0}, 
                  {1, 0, 0, 0}, 
                  {1, 0, 0, 0}, 
                  {1, 0, 0, 0}}, 1, 4}; 


// The  2 by 2 tile

struct tile t2 = {{{1, 1, 0, 0}, 
                  {1, 1, 0, 0}, 
                  {0, 0, 0, 0}, 
                  {0, 0, 0, 0}}, 2, 2};

// The S tile
struct tile t3 = {{{0, 1, 1, 0}, 
                  {1, 1, 0, 0}, 
                  {0, 0, 0, 0}, 
                  {0, 0, 0, 0}}, 3, 2};
// The Z tile
struct tile t4 = {{{1, 1, 0, 0}, 
                  {0, 1, 1, 0}, 
                  {0, 0, 0, 0}, 
                  {0, 0, 0, 0}}, 3, 2};

// The L tile
struct tile t5 = {{{1, 0, 0, 0}, 
                  {1, 0, 0, 0}, 
                  {1, 1, 0, 0}, 
                  {0, 0, 0, 0}}, 2, 3};

// The J tile
struct tile t6 = {{{0, 1, 0, 0}, 
                  {0, 1, 0, 0}, 
                  {1, 1, 0, 0}, 
                  {0, 0, 0, 0}}, 2, 3};

// The T tile
struct tile t7 = {{{1, 1, 1, 0}, 
                  {0, 1, 0, 0}, 
                  {0, 0, 0, 0}, 
                  {0, 0, 0, 0}}, 3, 2};







