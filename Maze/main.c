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

    do
    {
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
    
    //Ask the user if they want to save the current maze.
    printf("Do you want to save the current maze and its solution? Y/N : ");
    char request = 't';
    while(request != 'Y' && request != 'y' && request != 'N' && request != 'n')
        scanf("%c", &request);
    //save the matrix in a file.
    if (request == 'Y' || request == 'y')
    {
        safeMaze(yourMaze, r, c);
        printf("the maze was successfully safed.");
    }

    //Ask the user if they want to load a maze.
    printf("Do you want to load a maze? Y/N : ");
    do
    {
        scanf("%c", &request);
    } while (request != 'Y' && request != 'y' && request != 'N' && request != 'n');
    if (request == 'Y' || request == 'y')
    {
        //calculate how many safed mazes are in the file.
        int safedIndex = getSafedIndex();
        printf("there are %d mazes saved, which one do you want to load? Enter an index number between 0 < x < %d : ", safedIndex, (safedIndex + 1));
        r = -1;
        while(r <= 0 || r > safedIndex)
        {
            scanf("%d", &r);
        }
        //print selected maze.
        printf("maze from save index %d:\n ", r);
        loadMaze(r);
    }
    //Stop the terminal from closing and notify the user.
    printf("End of program.");
    system("pause");
}