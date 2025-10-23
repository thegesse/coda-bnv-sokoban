#ifndef __FUNCTION_H__
#define __FUNCTION_H__



#define GRID_HEIGHT 11
#define GRID_WIDTH 12

struct player{
    int old_pos_x;
    int old_pos_y;
    int pos_x;
    int pos_y;

};
//void movement(struct player *p, char key);
extern char grid[GRID_WIDTH][GRID_HEIGHT];
#endif