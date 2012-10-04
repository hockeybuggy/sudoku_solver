/*
 *FILENAME: solver.h
 *AUTHOR: Douglas Anderson
 *CREATED: 12/07/16
 *MODIFIED: 12/09/27
 */

// A cell is the fundamental data structure.
//   It holds a int and refences to the group it belongs to.
struct cell{
    int value;
    void * row; // Currently unused
    void * col;
    void * box;
};

// A group consists of nine cells
struct group{
    struct cell * cells[9];
};
// A puzzle consists of three collections of groups
struct puzzle{
    struct group * rows;
    struct group * cols;
    struct group * boxs;
};

// ---------  Constructor/Destructor  ------
void createGame(struct puzzle* game, char* gameStr);
// Creates a game an loads values into it
void freeGame(struct puzzle* game);
// Frees the games data structure

// ---------  Recursive function  ----------
int solve(struct puzzle* game, int x, int y);
// Recursivly solves the game via backtracking
//   x, y are the row and col number of the last move

// ---------  Other  -----------------------
int getNextFree(struct puzzle* game);
// returns the next free space in the puzzle
//   It starts at cell 0 and goes to cell 80

int getSquare(int x, int y);
// returns the square number by the row number and col number

struct puzzle* makeMove(struct puzzle* game, int row, int col, int val);
// Places a value int the square. row, col 1-9. val 0-9

// ---------  Boolean  ---------------------
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

// ---------  Printing  --------------------
void printPuzzle(struct puzzle* game);
// Prints the puzzle on 9 nine lines

void printPuzzleFlat(struct puzzle* game);
// Prints the puzzle as a string


