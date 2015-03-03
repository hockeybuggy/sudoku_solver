/*
 *FILENAME: solver.h
 *AUTHOR: Douglas Anderson
 */

// Recursivly solves the game via backtracing
int solve(puzzle_t* p, int x, int y);

// returns the next free space in the puzzle
int getNextFree(puzzle_t* p);

