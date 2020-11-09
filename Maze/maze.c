#include <stdlib.h>  // srand
#include <time.h>
#include <stdio.h>   // printf, scanf
#include "maze.h"

void createEmptyMaze(field *maze, int r, int c)
{
    // the empty maze's layout is an n times m Array of Fields, surrounded with walls. thus n+2 times m+2.
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            field currentField;
            if(i == (r - 1) || j == (c - 1) || i == 0 || j == 0)
            {
                currentField.state = 1;
                currentField.mark = 2;
			}
            else
            {
            	currentField.state = 0;
                currentField.mark = 0;
            }
			//if(j > 0)
                currentField.left = ((maze + ((c * i) + j - 1))->mark);
            //if(i < n)
                ((maze + ((c * i) + j - 1))->right) = currentField.mark;
            //if(i > 0)
                currentField.up = ((maze+ (c * i) + j - c)->mark);
            //if(j < m)
                ((maze + ((c * i )+ j- c))->down) = currentField.mark;
            *(maze + ((c * i) + j)) = currentField;
        }
    }
    printf("the empty maze's initialization was a success. \n");
}

void fillMaze(field *maze , int r, int c)
{
    int w;
    int randomRow, randomCol, flag;
    srand(time(0));		// seeds the random numbergenerator time based once at the start of the program.
    for(int i = 2; i <= 3; i++)
    {
        flag = 0;
        while(flag == 0)
        {
            randomRow = randomGen(1, r);
            randomCol = randomGen(1, c);
            if(maze[(c * randomRow) + randomCol].state == 0)
            {
                maze[c * randomRow + randomCol].state = i;
                flag = 1;	// if the position for the entrance/exit is empty, than place it there.
            }
        }
    }

    printf("Enter a poitive number of walls included in the maze: ");
    scanf("%u", &w);

    while(((r * c) - 2) < w)
    {
        printf("there are not enough free spaces for so many walls. Maximum free spaces: %d , please enter a new amount of walls: ", (r * c - 2));
        scanf("%u", &w);	// check if there is enough free space for an entry and an exit plus the requested amount of walls.
    }

    for(int i = 0; i < w; i++)
    {
    	flag = 0;
    	while(flag == 0)
    	{
    		randomRow = randomGen(1, r);
        	randomCol = randomGen(1, c);
        	if(maze[c * randomRow + randomCol].state == 0)
        	{
           		// if the position for the new wall is empty, than make a wall and go out of the while, else try again until you found a position that is empty.
            	maze[c * randomRow + randomCol].state = 1;
            	maze[c * randomRow + randomCol].mark = 2;
            	flag = 1;
        	}
    	}
    }
    printf("The initializations of your filled maze was successful. \n");
}

int randomGen(int min, int max)
{
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

void getMatrix(field *maze, int c, int size)
{
    int i=1;
    while(i <= size)
    {
        printf("%d", (maze + i - 1)->state);
        if(i%c == 0)
        {
            printf("\n");
        }
        i++;
    }
    printf("This is the maze created for you. \n");
}

int seeker(field *pMaze, int r, int c)
{
    field *pCurrent = seekerEntrance(pMaze, (r * c));
    field *pOld;
    printf("\nup %d \n", (pCurrent->up));
    printf("\ndown %d \n", (pCurrent->down));
    printf("\nleft %d \n", (pCurrent->left));
    printf("\nright %d \n", (pCurrent->right));
    int choices = (pCurrent->up) + (pCurrent->down) + (pCurrent->left) + (pCurrent->right);
	printf("%d", choices);
    int up, down, left, right;
    int destination = 0;
    while(choices<8)
    {
        if(pCurrent->state == 3)
            return 1;
        up = pCurrent->up;
        down = pCurrent->down;
        left = pCurrent->left;
        right = pCurrent->right;
        int pMin = getMin(getMin(up, down), getMin(left, right));
        int pMax = getMax(getMax(up, down), getMax(left, right));
        if(choices>=4) //straight way
        {
            findLowest(up, down, left, right, pMin, destination);
            moveToLowest(pCurrent, pOld, destination, c);
        }
        else	//crossings
        {
            if(pMax == 0)
                moveToLowest(pCurrent, pOld, destination, c);	//no need to set a destination.
            else if(pMax > 0)
            {
            	//check if the current was known or not, if not move backwards, else move forward.
                if(pOld->mark == 0)
                {
                    pCurrent->mark = 2;
                    field *pHelp;
                    pHelp = pOld;
                    pOld = pCurrent;
                    pCurrent = pOld;
                }
                else
                {
                    findLowest(up, down, left, right, pMin, destination);
                    moveToLowest(pCurrent, pOld, destination, c);
                }
            }
        }
        choices = (pCurrent->up) + (pCurrent->down) + (pCurrent->left) + (pCurrent->right);
    }
    if(choices<8)
    	return 0;
	else if(pCurrent->state == 3)
    	return 1;
    else
    	return 2;
}

field* seekerEntrance(field *pMaze, int max){
    int i = 0;
    field *entrance;
    while (i < max)
    {
        entrance = (pMaze+i);
        if(entrance->state == 2)
            return entrance;
        else
        	i++;
    }
    printf("\n Error, no entrance found \n");
}

void findLowest(int up, int down, int left, int right, int pMin, int destination)
{
    if(up == pMin)
        destination = 1;
    else if(down == pMin)
        destination = 3;
    else if(right == pMin)
        destination = 2;
    else if(left == pMin)
        destination = 4;
    else
        printf("\n error, there is no lowest possible move \n");
}

void moveToLowest(field *pCurrent, field *pOld, int destination, int c)
{
    field *pMoved;
    if(destination == 1)
        pMoved = pCurrent - c;
    else if(destination == 2)
        pMoved = pCurrent + 1;
    else if(destination == 3)
        pMoved = pCurrent + c;
    else
        pMoved = pCurrent - 1; //thus if all chances are equal the program will turn left.
	destination = 0;
    pOld = pCurrent;
    pCurrent = pMoved;
    pOld->mark += 1;
}

int getMax(int x, int y)
{
    return x > y ? x : y;
}

int getMin(int x, int y)
{
    return x < y ? x : y;
}

void getMarks(field *maze, int c, int size, int solution)
{
    if(solution == 0)
        printf("\n there is no possible solution for the maze.\n");
    else if(solution == 1)
        printf("\n A solution for the maze was found. \nThis is the marked solution of the seeker: The fields marked with a 1 are the fields of the exit path. \n");
    else if(solution == 2)
        printf("came here\n");
    int i=1;
    while(i <= size)
    {
        printf("%d", maze[i-1].mark);
        if(i%c == 0)
            printf("\n");
    	i++;
    }
}

void saveMaze(field *maze)
{

}