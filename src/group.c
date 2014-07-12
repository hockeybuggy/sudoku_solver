/*
 *FILENAME: group.c
 *AUTHOR: Douglas Anderson
 */

#include <stdlib.h>
#include <malloc.h>
#include "group.h"

int group_is_valid(group_t* g){
    int exists[9];
    for(int i = 0; i < 9; i++){
        exists[i] = 0;
    }
    for(int i = 0; i < 9; i++){ // TODO make these the method calls
        if(g->cells[i]->value != 0){
            if(exists[g->cells[i]->value - 1] == 0){
                exists[g->cells[i]->value - 1] = 1;
            }
            else{
                return(0);
            }
        }
    }
    return(1);
}

int group_is_complete(group_t* g){
    int count = 0;
    for(int i = 0; i < 9; i++){
        if(g->cells[i]->value != 0){
            count++;
        }
    }
    if(count != 9){
        return(1);
    }
    return(0);
}

