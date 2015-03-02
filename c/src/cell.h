/*
 *FILENAME: cell.h
 *AUTHOR: Douglas Anderson
 */

#ifndef CELL_H
#define CELL_H

typedef struct cell{
    int value;
} cell_t;

cell_t* cell_create();

void cell_set(cell_t* c, int value);

int cell_get(cell_t* c);

void cell_free(cell_t* c);

#endif
