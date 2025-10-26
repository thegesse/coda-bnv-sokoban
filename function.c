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

void update(struct player *p, struct goal *g) {
    grid[p->old_pos_x][p->old_pos_y] = '\x20';   //update player model
    grid[p->pos_x][p->pos_y] = '\x4f';
    grid[g->goal_x][g->goal_y] = '\x2E';   //keep goal on the board prevent from disapearing
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
    if(grid[p->pos_x][p->pos_y] == '\x23'){    //to limit player to walls
        p->pos_x = p->old_pos_x;
        p->pos_y = p->old_pos_y;
    }

    if(grid[p->pos_x][p->pos_y] == '\x58'){    //to move the box
        b->box_old_pos_x = b->box_pos_x;
        b->box_old_pos_y = b->box_pos_y; 
        switch(key){
            case 'w':
                b->box_pos_x -= 1;
                grid[b->box_old_pos_x][b->box_old_pos_y] = '\x20';
                grid[b->box_pos_x][b->box_pos_y] = '\x58';
                break;
            case 's':
                b->box_pos_x += 1;
                grid[b->box_old_pos_x][b->box_old_pos_y] = '\x20';
                grid[b->box_pos_x][b->box_pos_y] = '\x58';
                break;
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


int check_loss(struct box *b) {   //check if the box touches a wall piece

    if (b->box_pos_x <= 0 || b->box_pos_x >= 9 || 
        b->box_pos_y <= 0 || b->box_pos_y >= 9) {
        return 2;
    }
    return 0;
}

int check_win(struct box *b, struct goal *g) {
    if (check_loss(b) == 2) {   //loss the box exited the map
        return 2;
    }
    
    if (grid[b->box_pos_x][b->box_pos_y] == grid[g->goal_x][g->goal_y]) {   //win box == goal
        return 1;
    } else {
        return 0;
    }
}


int coords() {  //coords generation for player and box
    int random_number = rand() % 8 + 1;

    return random_number;
    
}
int box_coords() {   //different coords generation for box to avoid spawning near walls
    int random_number = rand() % 6 + 1;  

    return random_number;
    
}



