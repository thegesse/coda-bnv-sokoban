#include <stdlib.h>
#include <stdio.h>
#include "function.h"

int main(){
    struct player p;
    struct box b;
    struct goal g;
    int game_state = 1;

    p.pos_x = 4;
    p.pos_y = 8;
    b.box_pos_x = 4;
    b.box_pos_y = 4;
    g.goal_x = 5;
    g.goal_y = 2;
    
    char key;  //get player inputs
    grid[4][4] = 'X'; //place box for debug
    grid[4][8] = 'O';
    grid[5][2] = '.';

    draw_grid();

    while (game_state == 1) {
        printf("Enter move: ");
        key = getchar();  // Read a single character
        getchar();        // Consume the newline left in buffer
        if (key == 'x') {
            printf("Exiting game.\n");
            break;
        }

        

        movement(&p, key);
        constraints(&p, &b, key);
        system("clear");
        update(&p);
        check_win(&b, &g);

        if(check_win(&b, &g) == 1){
            printf("you won\n");
            game_state ++;
        }

    }


    return 0;
}

