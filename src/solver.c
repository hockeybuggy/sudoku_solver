/*
 *FILENAME: solver.c
 *AUTHOR: Douglas Anderson
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "puzzle.h"
#include "solver.h"

#define BUFFER_SIZE 1024
#define DEBUG 0

int main(int argc, char* argv[]){
    int result;
    char gameStr[BUFFER_SIZE];
    puzzle_t* puzzle;

    if(argc != 2){
        printf("Usage: solver [Game String]\n");
        return(1);
    }
    strncpy(gameStr, argv[1], BUFFER_SIZE);
    puzzle = puzzle_create(gameStr);

    #if DEBUG
    print_puzzle(puzzle, 0);
    printf("Puzzle validity:%d \n", puzzle_is_valid(puzzle));
    printf("Puzzle completeness:%d \n", puzzle_is_complete(puzzle));
    #endif
    result = solve(puzzle, -1, -1); // This recursively solves the puzzle

    #if DEBUG
    puzzle_print(game);
    printf("Puzzle validity:%d \n", puzzle_is_valid(puzzle));
    printf("Puzzle completeness:%d \n", puzzle_is_complete(puzzle));
    #else
    puzzle_print(puzzle, 1);
    #endif

    puzzle_free(puzzle);
    return(result);
}

int solve(struct puzzle* p, int x, int y){
    int nextFree;
    if(x == -1 || y == -1){
        if(puzzle_is_valid(p) == 0){
            return(0);
        }
    }
    else{
        if(puzzle_move_is_valid(p, x, y) == 0){
            return(0);
        }
    }
    if(puzzle_is_complete(p) == 1){
        return(1); // The p is valid and complete
    }
    nextFree = getNextFree(p);
    if(nextFree < 0){
        return(0);
    }

    // Backtracking
    for(int i = 1; i <= 9; i++){
        puzzle_set(p, nextFree/9, nextFree%9, i); // Try next number
        if(solve(p, nextFree/9, nextFree%9) == 1){
            return(1);
        }
        puzzle_set(p, nextFree/9, nextFree%9, 0); // Resets to zero
    }
    return(0);
}

int getNextFree(puzzle_t* p){
    for(int i = 0; i < 81; i++){
        if(p->rows[i/9].cells[i%9]->value == 0){
            return(i);
        }
    }
    return(-1);
}

