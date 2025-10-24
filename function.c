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

void draw_grid(){
    printf("Full grid:\n");
    for (int i = 0; i < 1; ++i) {
        printf("%s", grid[i]);
    }
}

void update(struct player *p) {
    grid[p->old_pos_x][p->old_pos_y] = '\x20'; //play with these 
    grid[p->pos_x][p->pos_y] = '\x4f';
    draw_grid();
}


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

void constraints(struct player *p, struct box *b, char key) { //reminder to fix
    if(grid[p->pos_x][p->pos_y] == '\x23'){
        p->pos_x = p->old_pos_x;
        p->pos_y = p->old_pos_y;
    }
    else if(grid[p->pos_x][p->pos_y] == grid[b->box_pos_x][b->box_pos_y] ){
        b->box_old_pos_x = b->box_pos_x;
        b->box_old_pos_y = b->box_pos_y;
        switch(key){
            case 'z':
                b->box_pos_x -= 1;
                break;
            case 's':
                b->box_pos_x += 1;
                break;
            case 'q':
                b->box_pos_y -= 1;
                break;
            case 'd':
                b->box_pos_y += 1;
                break;
        }
    }
}

