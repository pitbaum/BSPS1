#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Field
{
	int state;  //state is a variable declaring if the Field is seen as a wall (1), walkable (0), exit (2)or entrance (3).
	int row;	// index relative position of the row.
	int col;	// index relative positon of the column.
} field;

void createEmptyMaze(int n, int m);

void fillMaze( int pMin, int pMax);

int randomGen(int min, int max);

int seeker();

field *yourMaze = (field*) malloc(sizeof(field));

void main()
{
	unsigned int r,c;	// unsigned, since it anyways needs to be > 0.

	do
	{
		printf("Enter a new positive number of rows for the maze: ");	// r needs to be bigger than 0.
		scanf("%u", &r);
	} while(r <= 0);
	
	do{
		printf("Enter a new positive number of columns for the maze: ");
		scanf("%u", &c);
	} while(c <= 0);
	
	createEmptyMaze(r, c);	//create a new empty maze
	fillMaze(r, c);		//fill the empty maze with an entrance, walls and an exit.
	seeker();
}

void createEmptyMaze(int n, int m)
{
	//static field map[(n+2)*(m+2)]; 	// the empty maze's layout is an n times m Array of Fields, surrounded with walls. thus n+2 times m+2.
	yourMaze = realloc(yourMaze, ((n+2)*(m+2)) * sizeof(field));
	//map = (field*) malloc(((n+2)*(m+2)) * sizeof(field));
	
	for(int i=0; i < (n+2); i++)
	{
		for(int j=0; j < (m+2); j++)
		{
			field currentField;
			if(i == (n+1) || j == (m+1) || i == 0 || j==0)
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
			*(yourMaze+(m*i)+j) = currentField;
		}
	}
	printf("the empty maze's initialization was a success. \n");
}

void fillMaze(int pRow, int pCol)
{
	unsigned int w;
	int randomRow, randomCol, flag;
	srand(time(0));				// seeds the random numbergenerator time based once at the start of the program.
	for(int i = 2; i <= 3; i++)
	{
		flag = 0;
		while(flag == 0)
		{
			randomRow = randomGen(0, pRow);
			randomCol = randomGen(0, pCol);
			if(yourMaze[(pCol*randomRow) + randomCol].state == 0)
			{
				yourMaze[pCol*randomRow + randomCol].state = i;
				flag = 1;
					// if the position for the entrance/exit is empty, than place it there.
			}
		}
	}
	
	printf("Enter a poitive number of walls included in the maze: ");
	scanf("%u", &w);
	
	while(((pRow*pCol)-2) < w)
	{
		printf("there are not enough free spaces for so many walls. Maximum free spaces: %d , please enter a new amount of walls. \n", (pRow*pCol-2));
		scanf("%u", &w);
		// check if there is enough free space for an entry and an exit plus the requested amount of walls.
	}
	
	for(int i = 0; i < w; i++)
	{
		flag = 0;
		while(flag == 0)
		{
			randomRow = randomGen(pRow, pCol);
			randomCol = randomGen(pRow, pCol);
			if(yourMaze[pCol*randomRow + randomCol].state == 0)
			{
				yourMaze[pCol*randomRow + randomCol].state = 1;
				flag = 1;
				// if the position for the new wall is empty, than make a wall and go out of the while, else try again until you found a position that is empty.
			}

		}
		
	}
	printf("The initializations of your filled maze was successful. \n");
}

int randomGen(int min, int max)
{
	int num = (rand()%(max - min + 1)) + min;
	return num;
}

int seeker(field *pMaze)
{
	printf("came here. \n");
	return 1;
}
