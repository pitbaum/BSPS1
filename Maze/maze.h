    /**A single Field consists of:
     * "state" : a variable telling how the Field is seen.
     *  walkable ' ', a wall '*', entrance 'E', exit 'U'.
     **/
typedef struct Field
{ 
    char state;
} field;

void createEmptyMaze(field *maze, int r, int c);

void fillMaze(field *maze , int r, int c);

int randomGen(int min, int max);

void getMatrix(field *maze, int c, int size);

field* seekerEntrance(field *maze, int size);

field* seeker(field *pCurrent, int *stepcount, int c, int *path);

void solutionMapper(field *yourMaze, field *pEntrance, int r, int c, int *path, int stepCount);

void safeMaze(field *maze, int r, int c);

void loadMaze(int request);

int getSafedIndex();