#include <stdlib.h>
#include <stdio.h>
#include "function.h"

int main(){
    struct player p;
    p.pos_x = 4;
    p.pos_y = 8;

    char key;  //get player inputs
    grid[2][2] = 'X'; //place box for debug
    grid[4][8] = 'O'; //hexa =  4F turns to N because hexa - 1 turns to 4E
    grid[5][2] = '.';

    draw_grid();

    while (1) {
    printf("Enter move: ");
    key = getchar();  // Read a single character
    getchar();        // Consume the newline left in buffer
    if (key == 'x') {
        printf("Exiting game.\n");
        break;
    }
    movement(&p, key);
    system("clear");
    update(&p);
    }


    return 0;
}


