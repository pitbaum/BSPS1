#include <stdio.h>   // printf, scanf
#include <stdlib.h>  // malloc
#include "maze.h"

void main()
{
    int r, c;
    do
    {
        printf("Enter a new positive number of rows for the maze: ");	// r needs to be bigger than 0.
        scanf("%u", &r);
    } while(r <= 0);

    do{
        printf("Enter a new positive number of columns for the maze: ");
        scanf("%u", &c);
    } while(c <= 0);
    r += 2;
    c += 2;
    field *yourMaze = (field*) malloc((r * c) * sizeof(field));
    createEmptyMaze(yourMaze, r, c);	//create a new empty maze.
    fillMaze(yourMaze, r, c);		//fill the empty maze with an entrance, walls and an exit.
    getMatrix(yourMaze, c, (r * c));	//prints the maze to the terminal.
    int solution = seeker(yourMaze, r, c);		//looks for the entrance.
    getMarks(yourMaze, c, (r * c), solution); //prints the solution to the terminal
}