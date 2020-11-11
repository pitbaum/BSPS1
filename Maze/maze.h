typedef struct Field
{
    int state;  //state is a variable declaring if the Field is seen as walkable (0) a wall (1) or entrance (2), exit (3).
    int up;	// points to the mark of the upper field.
    int down;
    int left;
    int right;
    int mark;
} field;

void createEmptyMaze(field *maze, int r, int c);

void fillMaze(field *maze , int r, int c);

int randomGen(int min, int max);

void getMatrix(field *maze, int c, int size);	// size is the index of the last field in the list.

int seeker(field *maze, int r, int c);

field* seekerEntrance(field *pMaze, int size);

int findLowest(int up, int down, int left, int right, int pMin);

int moveToChoice(field *pCurrent, field *pOld, int c, int choice);

int getMax(int x, int y);

int getMin(int x, int y);

int isWalkable(int direction);

void getSolution(field *maze, int c, int size, int solution);

int move(int up, int down, int left, int right, int pMin, field *pCurrent, field *pOld, int c);

int moveBackwards(int lastchoice,  field *pCurrent, field *pOld, int c);