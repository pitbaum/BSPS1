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
    printf("This is the maze created for you. \n");

    //creates a pointer that points to the field with the entrance of the maze.
    field *pEntrance = seekerEntrance(yourMaze, (r * c));
    //creating an integer list containing the moves made by the seeker.
    int path[r*c];
    //number of moves to get from the entrance to the exit.
    int stepCount = 0;
    field *pCurrent = pEntrance;

    //let's the seeker look for a possible way to the Exit.
    seeker(pCurrent, &stepCount, c, &path[0]);
    pEntrance->state = 'E';
    
    //evaluates the seekers solution.
    if(stepCount > 0)
    {
        printf("A solution for your maze was found.\n");
        pEntrance = seekerEntrance(yourMaze, (r * c));
        solutionMapper(yourMaze, pEntrance, r, c, &path[0], stepCount);
    }
    else
        printf("There was no way to the exit found.\n");
    pEntrance->state = 'E';
    getMatrix(yourMaze, c, (r * c));
}