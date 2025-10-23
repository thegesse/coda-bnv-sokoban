#include <stdlib.h>
#include <stdio.h>
#include "function.h"

int main(){
    int key;  //get player inputs
    grid[2][2] = 'X'; //place box for debug
    grid[4][8] = 'O';
    grid[5][2] = '.';


    printf("Full grid:\n");
    for (int i = 0; i < 1; ++i) {
        printf("%s", grid[i]);
    }



    return 0;
}
