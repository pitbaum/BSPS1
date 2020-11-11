#include <stdio.h>   // printf, scanf
#include <stdlib.h>  // malloc
#include "maze.h"

void main()
{
    int r, c;
    //r and c need to be bigger than 1.
    do
    {
        printf("Enter a new positive number of rows for the maze: ");
        scanf("%u", &r);
    } while(r <= 1);

    do{
        printf("Enter a new positive number of columns for the maze: ");
        scanf("%u", &c);
    } while(c <= 1);

    //the empty maze's layout is an n times m Array of Fields, surrounded with walls. thus n+2 times m+2.
    r += 2;
    c += 2;

    //allocate memory.
    field *yourMaze = (field*) malloc((r * c) * sizeof(field));
    //create a new empty maze.
    createEmptyMaze(yourMaze, r, c);
    //fill the empty maze with an entrance, walls and an exit.
    fillMaze(yourMaze, r, c);
    //prints the maze to the terminal.
    getMatrix(yourMaze, c, (r * c));
    //looks for the entrance.
    int solution = seeker(yourMaze, r, c);
    //prints the solution to the terminal
    getSolution(yourMaze, c, (r * c), solution);
}