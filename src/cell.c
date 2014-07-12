/*
 *FILENAME: cell.c
 *AUTHOR: Douglas Anderson
 */

#include <stdlib.h>
#include <malloc.h>
#include "cell.h"

void cell_set(cell_t* c, int value){
    c->value = value;
}

int cell_get(cell_t* c){
    return c->value;
}

