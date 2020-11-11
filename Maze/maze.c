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
                flag = 1;
            }
        }
    }

    printf("Enter a poitive number of walls included in the maze: ");
    scanf("%u", &w);

    // check if there is enough free space for an entry and an exit plus the requested amount of walls.
    while(((r * c) - 2) < w)
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
        	if(maze[c * randomRow + randomCol].state == 0)
        	{
            	maze[c * randomRow + randomCol].state = 1;
            	maze[c * randomRow + randomCol].mark = 2;
            	flag = 1;
        	}
    	}
    }
    printf("The initializations of your filled maze was successful. \n");
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

/**Starts a seeker that looks for an exit.
 * The seeker uses a variant of the Trémaux method to find an exit.
 * If the seeker is surrounded by walls or already twice walked fields, end seeking.
 * If the seeker gets to a crossing unknown to it, take a random path (normally left).
 * If the seeker gets to a crossing it already saw before, it will turn back around.
 * If the seeker is in a straight corridor it will move forward into the direction it was heading before.
 **/
int seeker(field *pMaze, int r, int c)
{
    field *pCurrent = seekerEntrance(pMaze, (r * c));
    field *pOld;
    int lastChoice;
    int up = pCurrent->up;
    int down = pCurrent->down;
    int left = pCurrent->left;
    int right = pCurrent->right;
    int sumOfWalls = isWalkable(up) + isWalkable(down) + isWalkable(left) + isWalkable(right);
    while(sumOfWalls < 4)
    {
        //Exit found.
        if(pCurrent->state == 3)
            return 1;
        int pMin = getMin(getMin(up, down), getMin(left, right));
        int pMax = getMax(getMax(up, down), getMax(left, right));

        /**Crossing with 4 choices or 3 choices.
         * Check if known, -> no? choose one. -> yes? move the way back that you came from.
         **/ 
        if(sumOfWalls < 2)
        {
            if(pMax == 0)
                lastChoice = move(up, down, left, right, pMin, pCurrent, pOld, c);
            else if(pMax == 1 && pMin == 0)
                lastChoice = moveBackwards(lastChoice, pCurrent, pOld, c);
            else
                lastChoice = move(up, down, left, right, pMin, pCurrent, pOld, c);
                            
        }
        //straight way with 2 choices, continue the route already taken if possible else do crossing choice.
        else if(sumOfWalls == 2)
        {
            if(lastChoice == 1)
            {
                if(isWalkable(up) == 0)
                    moveToChoice(pCurrent, pOld, c, lastChoice);
                else
                    lastChoice = move(up, down, left, right, pMin, pCurrent, pOld, c);
            }
            else if(lastChoice == 2)
            {
                if(isWalkable(down) == 0)
                    moveToChoice(pCurrent, pOld, c, lastChoice);
                else
                lastChoice = move(up, down, left, right, pMin, pCurrent, pOld, c);
            }
            else if(lastChoice == 3)
            {
                if(isWalkable(right) == 0)
                    moveToChoice(pCurrent, pOld, c, lastChoice);
                else
                    lastChoice = move(up, down, left, right, pMin, pCurrent, pOld, c);
            }
            else if(lastChoice == 4)
            {
                if(isWalkable(left) == 0)
                    moveToChoice(pCurrent, pOld, c, lastChoice);
                else
                    lastChoice = move(up, down, left, right, pMin, pCurrent, pOld, c);
            }
            else
                lastChoice = move(up, down, left, right, pMin, pCurrent, pOld, c);
        }
        //Only 1 possible choice to go to.
        else if(sumOfWalls == 3)
        {
                int choice = findLowest(up, down, left, right, pMin);
                lastChoice = moveToChoice(pCurrent, pOld, c, choice); 
        }

        up = pCurrent->up;
        down = pCurrent->down;
        left = pCurrent->left;
        right = pCurrent->right;
        sumOfWalls = isWalkable(up) + isWalkable(down) + isWalkable(left) + isWalkable(right);
    }

    //return the solution the seeker came to.
    if(sumOfWalls == 4)
    	return 0;
	else if(pCurrent->state == 3)
    	return 1;
    else
    	return 2;
}

//Looks for the entrance Field and returns a pointer to it.
field* seekerEntrance(field *pMaze, int max)
{
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

/**Looks for the lowest mark out of the adjacent fields.
*If all are the same move left.
*If some are the same, take the first.
**/
int findLowest(int up, int down, int left, int right, int pMin)
{
    if(up == pMin)
        return 1;
    else if(down == pMin)
        return 2;
    else if(right == pMin)
        return 3;
    else if(left == pMin)
        return 4;
    else
        printf("\n error, there is no lowest possible move \n");
}

//Updates the pointer values of the maze to the move made with the entered choice.
int moveToChoice(field *pCurrent, field *pOld, int c, int choice)
{
    field *pMove;
    //move up.
    if(choice == 1)
        pMove = (pCurrent - c);
    //move right.
    else if(choice == 2)
        pMove = (pCurrent + 1);
    //move down.
    else if(choice == 3)
        pMove = (pCurrent + c);
    //move left.
    else
        pMove = (pCurrent - 1);

    //update values.
    pOld->mark += 1;
    pOld = pCurrent;
    pCurrent = pMove;
    return choice;
}

//returns the maximum of the parameters.
int getMax(int x, int y)
{
    return x > y ? x : y;
}

//returns the minimum of the parameters.
int getMin(int x, int y)
{
    return x < y ? x : y;
}

//returns if the chosen direction is walkable or a wall.
int isWalkable(int direction)
{
    if (direction == 2)
        return 1;
    else
        return 0;
}

//prints out the solution the Seeker has found for the maze.
void getSolution(field *maze, int c, int size, int solution)
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

//Chooses a move the seeker should go to and makes that move.
int move(int up, int down, int left, int right, int pMin, field *pCurrent, field *pOld, int c)
{
    int choice = findLowest(up, down, left, right, pMin);
    int lastChoice = moveToChoice(pCurrent, pOld, c, choice);
    return lastChoice;
}

//moves into the direction it came from.
int moveBackwards(int lastChoice, field *pCurrent, field *pOld, int c)
{
    int choice;
    if(lastChoice == 1)
        choice = 3;
    else if(lastChoice == 2)
        choice = 4;
    else if(lastChoice == 3)
        choice = 1;
    else
        choice = 2;
    lastChoice = moveToChoice(pCurrent, pOld, c, choice);
    return lastChoice;
}