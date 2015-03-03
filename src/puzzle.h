/*
 *FILENAME: puzzle.h
 *AUTHOR: Douglas Anderson
 */

#ifndef PUZZLE_H
#define PUZZLE_H

#include "group.h"

typedef struct puzzle{
    group_t* rows;
    group_t* cols;
    group_t* boxs;
} puzzle_t;

puzzle_t* puzzle_create(char* puzzle_str);

int puzzle_get(puzzle_t* p, int row, int col);

int puzzle_set(puzzle_t* p, int row, int col, int val);

int puzzle_is_valid(puzzle_t* p);

int puzzle_move_is_valid(puzzle_t* p, int row, int col);

int puzzle_is_complete(puzzle_t* p);

void puzzle_print(puzzle_t* p, int flat);

void puzzle_free(puzzle_t* p);

#endif

