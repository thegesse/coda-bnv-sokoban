#ifndef __FUNCTION_H__
#define __FUNCTION_H__



#define GRID_HEIGHT 11
#define GRID_WIDTH 12
#define PLAYER_MODEL 4F  //hex for 'O'

struct player {
    int old_pos_x;
    int old_pos_y;
    int pos_x;
    int pos_y;
    int show;
    int movement;
};

struct box {
    int box_old_pos_x;
    int box_old_pos_y;
    int box_pos_x;
    int box_pos_y;
    int box_show;
    int box_movement;
};

struct goal {
    int goal_x;
    int goal_y;
};

void movement(struct player *p, char key);

extern char grid[GRID_WIDTH][GRID_HEIGHT];
void draw_grid();
void update(struct player *p);
void constraints(struct player *p, struct box *b, char key);
#endif