#include <stdio.h>
#include <stdlib.h>
#include "function.h"



char grid[GRID_WIDTH][GRID_HEIGHT]={
    "##########\n",
    "#        #\n",
    "#        #\n",
    "#        #\n",
    "#        #\n",
    "#        #\n",
    "#        #\n",
    "#        #\n",
    "#        #\n",
    "##########\n",
    
};

void movement(struct player *p, char key){
    p->old_pos_x = p->pos_x;
    p->old_pos_y = p->pos_y;
    switch(key) {
        case 'z':
            p->pos_x -= 1;
            break;
        case 's':
            p->pos_x += 1;
            break;
        case 'q':
            p->pos_y -= 1;
            break;
        case 'd':
            p->pos_y += 1;
            break;
    }
}

