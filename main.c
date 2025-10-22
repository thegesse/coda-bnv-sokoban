#include <stdlib.h>
#include <stdio.h>


int main(){
    int key;  //get player inputs
    int pos_x, pos_y  //get player position(located earlier in vid)
    int dest_count //for "." cells 

    printf("%s", grid);

    while(/*find end condition*/){
        switch(key)
        {
            case 'z':
                move_char(pos_x, pos_y, - MAP_WIDTH - 1);
                break;
            case 's':
                move_char(pos_x, pos_y, MAP_WIDTH + 1);
                break;
            case 'q':
                move_char(pos_x, pos_y, - 1);
                break;
            case 'd':
                move_char(pos_x, pos_y, + 1);
                break;



        }

    }

    return 0;
}