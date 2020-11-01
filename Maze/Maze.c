#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

typedef struct Field
{
	int state;  //state is a variable declaring if the Field is seen as a wall (1), walkable (0), exit (3)or entrance (2).
	int row;	// index relative position of the row.
	int col;	// index relative positon of the column.
} field;

void createEmptyMaze(field* emptyMaze, int n, int m);

void fillMaze(field* hollowMaze , int pMin, int pMax);

int randomGen(int min, int max);

void getMatrix(field* maze, int col, int size);	// size is the index of the last field in the list.

int seeker();

void saveMaze(field* maze);

void main()
{
	int r,c;
	do
	{
		printf("Enter a new positive number of rows for the maze: ");	// r needs to be bigger than 0.
		scanf("%u", &r);
	} while(r <= 0);
	
	do{
		printf("Enter a new positive number of columns for the maze: ");
		scanf("%u", &c);
	} while(c <= 0);
	r +=2;
	c +=2;
	field *yourMaze = (field*) malloc((r*c)*sizeof(field));
	createEmptyMaze(yourMaze, r, c);	//create a new empty maze
	fillMaze(yourMaze, r, c);		//fill the empty maze with an entrance, walls and an exit.
	getMatrix(yourMaze, c, (r*c)); 
	seeker();
}

void createEmptyMaze(field* emptyMaze, int n, int m)
{
	// the empty maze's layout is an n times m Array of Fields, surrounded with walls. thus n+2 times m+2.
	
	for(int i=0; i < n; i++)
	{
		for(int j=0; j < m; j++)
		{
			field currentField;
			if(i == (n-1) || j == (m-1) || i == 0 || j==0)
			{
				currentField.state = 1; 	// IF there is a wall, the field's state will be marked as 1.
				currentField.row = i;		// initialization of the index in a 2D matrix to the variable.
				currentField.col = j;
			}
			
			else
			{
				currentField.state = 0;
				currentField.row = i;
				currentField.col = j;
			}
			*(emptyMaze+(m*i)+j) = currentField;
		}
	}
	printf("the empty maze's initialization was a success. \n");
}

void fillMaze(field* hollowMaze , int pRow, int pCol)
{
	int w;
	int randomRow, randomCol, flag;
	srand(time(0));				// seeds the random numbergenerator time based once at the start of the program.
	for(int i = 2; i <= 3; i++)
	{
		flag = 0;
		while(flag == 0)
		{
			randomRow = randomGen(1, pRow);
			randomCol = randomGen(1, pCol);
			if(hollowMaze[(pCol*randomRow) + randomCol].state == 0)
			{
				hollowMaze[pCol*randomRow + randomCol].state = i;
				flag = 1;
					// if the position for the entrance/exit is empty, than place it there.
			}
		}
	}
	
	printf("Enter a poitive number of walls included in the maze: ");
	scanf("%u", &w);
	
	while(((pRow*pCol)-2) < w)
	{
		printf("there are not enough free spaces for so many walls. Maximum free spaces: %d , please enter a new amount of walls: ", (pRow*pCol-2));
		scanf("%u", &w);
		// check if there is enough free space for an entry and an exit plus the requested amount of walls.
	}
	
	for(int i = 0; i < w; i++)
	{
		flag = 0;
		while(flag == 0)
		{
			randomRow = randomGen(1, pCol);
			randomCol = randomGen(1, pCol);
			if(hollowMaze[pCol*randomRow + randomCol].state == 0)
			{
				hollowMaze[pCol*randomRow + randomCol].state = 1;
				flag = 1;
				// if the position for the new wall is empty, than make a wall and go out of the while, else try again until you found a position that is empty.
			}

		}
		
	}
	printf("The initializations of your filled maze was successful. \n");
}

int randomGen(int min, int max)
{
	int num = (rand() % (max-min+ 1))+ min;
	return num;
}

void getMatrix(field* maze, int col, int size)
{
	int i=1;
	while(i <= size)
	{
		printf("%d", maze[i-1].state);
		if(i%col == 0)
		{
			printf("\n");
		}
		i++;
	}
	printf("\n This is the maze created for you. \n");
}

int seeker(field *pMaze)
{
	printf("came here. \n");
	return 1;
}

void saveMaze(field* maze)
{
	//char cwd[Path_MAX];
	//ptr = fopen(getcwd(cwd, sizeof(cwd)), w);
	
	//fclose(fptr);
}
