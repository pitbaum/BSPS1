    /**A single Field consists of:
     * "state" : a variable declaring if the Field is seen as walkable (0) a wall (1) or entrance (2), exit (3).
     * a direction : tells the mark of the field next to it. 
     * "mark" : count of how often the field was already stepped upon. 
     * every Field is 2 times crossable.
     * Walls are marked as 3.
     **/
typedef struct Field
{
    //state ' ' if empty and Walkable, 'U' if Exit, 'E' if Entrance, '*' if Wall, 'X' if already walked over. 
    char state;
} field;

void createEmptyMaze(field *maze, int r, int c);

void fillMaze(field *maze , int r, int c);

int randomGen(int min, int max);

void getMatrix(field *maze, int c, int size);

field* seekerEntrance(field *maze, int size);

field* seeker(field *pCurrent, int *stepcount, int c, int *path);

void solutionMapper(field *yourMaze, field *pEntrance, int r, int c, int *path, int stepCount);