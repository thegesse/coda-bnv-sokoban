#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <time.h>



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
        case 'w':
            p->pos_x -= 1;
            break;
        case 's':
            p->pos_x += 1;
            break;
        case 'a':
            p->pos_y -= 1;
            break;
        case 'd':
            p->pos_y += 1;
            break;
    }
}

void constraints(struct player *p, struct box *b, char key) {
    if(grid[p->pos_x][p->pos_y] == '\x23'){
        p->pos_x = p->old_pos_x;
        p->pos_y = p->old_pos_y;
    }

    if(grid[p->pos_x][p->pos_y] == '\x58'){
        b->box_old_pos_x = b->box_pos_x;
        b->box_old_pos_y = b->box_pos_y;
        switch(key){
            case 'w':
                b->box_pos_x -= 1;
                grid[b->box_old_pos_x][b->box_old_pos_y] = '\x20';
                grid[b->box_pos_x][b->box_pos_y] = '\x58';
            case 's':
                b->box_pos_x += 1;
                grid[b->box_old_pos_x][b->box_old_pos_y] = '\x20';
                grid[b->box_pos_x][b->box_pos_y] = '\x58';
            case 'a':
                b->box_pos_y -= 1;
                grid[b->box_old_pos_x][b->box_old_pos_y] = '\x20';
                grid[b->box_pos_x][b->box_pos_y] = '\x58';
                break;

            case 'd':
                b->box_pos_y += 1;
                grid[b->box_old_pos_x][b->box_old_pos_y] = '\x20';
                grid[b->box_pos_x][b->box_pos_y] = '\x58';
                break;
        }
    }
}


int check_win(struct box *b, struct goal *g){
    if(grid[b->box_pos_x][b->box_pos_y] == grid[g->goal_x][g->goal_y]){
        return 1;
    }
    else {
        return 0;
    }
}

int random(struct random *r) {

    
}


