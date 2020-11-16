#include <stdlib.h>  //srand.
#include <time.h>   //system time.
#include <stdio.h>   //printf, scanf.
#include "maze.h"   //include header.

/**Creates at the memory allocation r*c field structs.
 * Every outer Field is marked as an outer wall, every wall is marked with a mark of 2.
 * The Fields inside the maze are initialized as walkable empty fields.
 **/
void createEmptyMaze(field *maze, int r, int c)
{
    //Seeding the random generator with the system time.
    srand ( time(NULL) );
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            field currentField;
            if(i == (r - 1) || j == (c - 1) || i == 0 || j == 0)
                currentField.state = '*';
            else
            	currentField.state = ' ';
            *(maze + ((c * i) + j)) = currentField;
        }
    }
    /**Generation of an entrance as one of the outter walls of the maze.**/
    int randomSide = randomGen(1, 4);
    if(randomSide == 1)
    {
        randomSide = randomGen(1, (c-2));
        (maze + randomSide)->state = 'E';
    }
    else if(randomSide == 2)
    {
        randomSide = randomGen(1, r-2);
        (maze + (c * randomSide))->state = 'E';
    }
    else if(randomSide == 3)
    {
        randomSide = randomGen(1, r-2);
        (maze + (c * randomSide) + c-1)->state = 'E';
    }
    else
    {
        randomSide = randomGen(1, (c-2));
        (maze + (c * (r-1) + randomSide))->state = 'E';
    }
}

/**Fills the maze with an entry and an exit.
 * Asks the user for an amount of walls.
 * Fills the maze with as many random postitioned walls as requested.
 **/
void fillMaze(field *maze , int r, int c)
{
    int w;
    int randomRow, randomCol, flag;
    // seeds the random number generator time based once at the start of the program.
    srand(time(0));

    /**Choose a random position for the entrance and exit.
     If the position for the entrance/exit is empty, than place it there.
     **/
        flag = 0;
        while(flag == 0)
        {
            randomRow = randomGen(1, r);
            randomCol = randomGen(1, c);
            if(maze[(c * randomRow) + randomCol].state == ' ')
            {
                maze[c * randomRow + randomCol].state = 'U';
                flag = 1;
            }
        }

    printf("Enter a poitive number of walls included in the maze: ");
    scanf("%u", &w);

    // check if there is enough free space for an exit plus the requested amount of walls.
    while(((r * c) - 1) < w)
    {
        printf("there are not enough free spaces for so many walls. Maximum free spaces: %d , please enter a new amount of walls: ", (r * c - 2));
        scanf("%u", &w);
    }

    /**Choose a random position for a wall.
      If the position for the wall is empty, than place it there.
     **/
    for(int i = 0; i < w; i++)
    {
    	flag = 0;
    	while(flag == 0)
    	{
    		randomRow = randomGen(1, r);
        	randomCol = randomGen(1, c);
        	if(maze[c * randomRow + randomCol].state == ' ')
        	{
            	maze[c * randomRow + randomCol].state = '*';
            	flag = 1;
        	}
    	}
    }
}

/**Generates random numbers between the given borders**/
int randomGen(int min, int max)
{
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

/**prints out the look of the maze as a r*c matrix**/
void getMatrix(field *maze, int c, int size)
{
    int i = 1;
    while(i <= size)
    {
        printf("%c", (maze + i - 1)->state);
        if(i%c == 0)
        {
            printf("\n");
        }
        i++;
    }
}

//Looks for the entrance Field and returns a pointer to it.
field* seekerEntrance(field *maze, int max)
{
    int i = 0;
    field *pEntrance;
    while (i <= max)
    {
        pEntrance = (maze + i);
        if(pEntrance->state == 'E')
            return pEntrance;
        else
        	i++;
    }
    printf("\n Error, no entrance found \n");
}

//Let's a Seeker look for an exit.
field* seeker(field *pCurrent, int *stepCount, int c, int *path)
{
    if(pCurrent->state == 'U')
        return pCurrent;
    if((pCurrent - c)->state ==  ' ' || (pCurrent - c)->state == 'U')
    {
        pCurrent->state = 'W';
        path[*stepCount] = -c;
        (*stepCount)++;
        pCurrent -= c;
        return seeker(pCurrent, stepCount, c, path); 
    }
    else if((pCurrent + 1)->state == ' ' || (pCurrent + 1)->state == 'U')
    {
        pCurrent->state = 'W';
        path[*stepCount] = 1;
        (*stepCount)++;
        pCurrent += 1;
        return seeker(pCurrent, stepCount, c, path);
    }
    else if((pCurrent + c)->state == ' ' || (pCurrent + c)->state == 'U')
    {
        pCurrent->state = 'W';
        path[*stepCount] = c;
        (*stepCount)++;
        pCurrent += c;
        return seeker(pCurrent, stepCount, c, path);
    }
    else if((pCurrent - 1)->state == ' ' || (pCurrent - 1)->state == 'U')
    {
        pCurrent->state = 'W';
        path[*stepCount] = -1;
        (*stepCount)++;
        pCurrent -= 1;
        return seeker(pCurrent, stepCount, c, path);
    }
    else
    {
        if(*stepCount > 0)
        {
            pCurrent->state = 'W';
            (*stepCount)--;
            int backwards = path[*stepCount];
            pCurrent -= backwards;
            return seeker(pCurrent, stepCount, c, path);
        }
        else
            return pCurrent;
    }
}

//cleans the matrix of the path the seeker took thorugh the maze and changes it to the path necessary for the seeker to find the Exit.
void solutionMapper(field *yourMaze, field *pEntrance, int r, int c, int *path, int stepCount)
{
    for (int i = 0; i < ((r * c)); i++)
    {
        if((yourMaze + i)->state == 'W')
            (yourMaze + i)->state = ' ';
    }
        field *pCurrent = pEntrance;
        for (int i = 0; i < (stepCount - 1); i++)
        {
            pCurrent += path[i];
            pCurrent->state = 'W';
        }
}