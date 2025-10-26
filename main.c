#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include <time.h>

int main(){
    srand(time(NULL));
    struct player p;
    struct box b;
    struct goal g;
    int game_state = 1;

    p.pos_x = coords();   //initialize coords
    p.pos_y = coords();
    b.box_pos_x = box_coords();
    b.box_pos_y = box_coords();
    g.goal_x = coords();
    g.goal_y = coords();
    
    char key;  
    grid[b.box_pos_x][b.box_pos_y] = 'X';  //draw symbols on grid
    grid[p.pos_x][p.pos_y] = 'O'; 
    grid[g.goal_x][g.goal_y] = '.';

    draw_grid();
    printf("Sokoban game, push the box so it reaches the goal('.'), dont push the box into the walls"
        "use wasd to move, x to exit game, the final grid is saved in the end.txt file. Good luck  :).\n");
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
        update(&p, &g);
        check_win(&b, &g);

        if(check_win(&b, &g) == 1){
            printf("you won\n");
            game_state ++;
        }
        else if(check_win(&b, &g) == 2){
            printf("you loose\n");
            game_state ++;
        }

    }
    FILE *fp = fopen("end.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
    }

    for (int i = 0; i < 1; ++i) {
        fprintf(fp, "%s", grid[i]); 
    }
    fclose(fp);

    return 0;
}

