/*
 *FILENAME: solver.h
 *AUTHOR: Douglas Anderson
 *CREATED: 12/07/16
 *MODIFIED: 12/07/29
 */

struct cell{
    int value;
    void * row; // Currently unused
    void * col;
    void * box;
};

struct group{
    struct cell * cells[9];
};

struct puzzle{
    struct group * rows;
    struct group * cols;
    struct group * boxs;
};

void createGame(struct puzzle* game, char* gameStr);
// Creates a game an loads values into it

void freeGame(struct puzzle* game);

int solve(struct puzzle* game, int x, int y);
// Recursivly solves the game via backtracing

int getNextFree(struct puzzle* game);
// returns the next free space in the puzzle

struct puzzle* makeMove(struct puzzle* game, int row, int col, int val);
// Places a value int the square. row, col 1-9. val 0-9

int getSquare(int x, int y);
// returns the square number by the row and col

int puzzleIsValid(struct puzzle* game);
// Returns TRUE if all groups are valid

int moveIsValid(struct puzzle* game, int x, int y);
// Returns TRUE if the groups pertanint to the move are valid

int groupIsValid(struct group* g);
// Returns TRUE if there are no duplicates in a group 

int puzzleIsComplete(struct puzzle* game);
// Returns TRUE if the puzzle is complete

int groupIsComplete(struct group* g);
// Returns TRUE if the group is complete

void printPuzzle(struct puzzle* game);
// Prints a representation of the puzzle

void printPuzzleFlat(struct puzzle* game);



