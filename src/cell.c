/*
 *FILENAME: cell.c
 *AUTHOR: Douglas Anderson
 */

#include <stdlib.h>
#include <malloc.h>
#include "cell.h"

cell_t* cell_create(){
    cell_t* c = malloc(sizeof(cell_t));
    c->value = 0;
    return c;
}

void cell_set(cell_t* c, int value){
    c->value = value;
}

int cell_get(cell_t* c){
    return c->value;
}

void cell_free(cell_t* c){
    free(c);
}
