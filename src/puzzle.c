/*
 *FILENAME: puzzle.c
 *AUTHOR: Douglas Anderson
 */

#include <stdlib.h>
#include <malloc.h>
#include "puzzle.h"

static int getSquare(int x, int y){
    /*This function returns the correct square the cell should be in*/
    if(x<3 && y<3){
        return(0);
    }
    else if(x<3 && y<6){
        return(1);
    }
    else if(x<3 && y<9){
        return(2);
    }
    else if(x<6 && y<3){
        return(3);
    }
    else if(x<6 && y<6){
        return(4);
    }
    else if(x<6 && y<9){
        return(5);
    }
    else if(x<9 && y<3){
        return(6);
    }
    else if(x<9 && y<6){
        return(7);
    }
    else if(x<9 && y<9){
        return(8);
    }
    return(-1);
}

puzzle_t* puzzle_create(char* puzzle_str){
    puzzle_t* p = malloc(sizeof(puzzle_t));
    p->rows = malloc(sizeof(group_t)*9);
    p->cols = malloc(sizeof(group_t)*9);
    p->boxs = malloc(sizeof(group_t)*9);
    for(int i = 0; i < 81; i++){
        p->rows[i/9].cells[i%9] = malloc(sizeof(cell_t));
        p->rows[i/9].cells[i%9]->value = puzzle_str[i] - 48;
        /*printf("square number:%d, value:%c\n", i, pStr[i]);*/
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            p->cols[j].cells[i] = p->rows[i].cells[j];
            p->boxs[getSquare(i,j)].cells[(i%3)*3+(j%3)] = p->rows[i].cells[j];
        }
    }
    return(p);
}

int puzzle_get(puzzle_t* p, int row, int col){
    return p->rows[row].cells[col]->value;
}

int puzzle_set(puzzle_t* p, int row, int col, int val){
    if(row < 0 || row > 8 || col < 0 || col > 8){
        printf("Not a valid square r:%d c:%d \n", row, col);
        return(-1);
    }
    if(val < 0 || val > 9){
        printf("Not a valid value\n");
        return(-1);
    }
    p->rows[row].cells[col]->value = val;
    return(1);
}

int puzzle_is_valid(puzzle_t* p){
    for(int i = 0; i < 9; i++){
        if(group_is_valid(&p->rows[i]) != 1){
            return(0);
        }
        if(group_is_valid(&p->cols[i]) != 1){
            return(0);
        }
        if(group_is_valid(&p->boxs[i]) != 1){
            return(0);
        }
    }
    return(1);
}

int puzzle_move_is_valid(puzzle_t* p, int row, int col){
    if(group_is_valid(&p->rows[row]) != 1){
        return(0);
    }
    if(group_is_valid(&p->cols[col]) != 1){
        return(0);
    }
    if(group_is_valid(&p->boxs[getSquare(row,col)]) != 1){
        return(0);
    }
    return(1);
}

int puzzle_is_complete(puzzle_t* p){
    int count = 0;
    for(int i = 0; i < 9; i++){
        if(group_is_complete(&p->rows[i]) != 1){
            count++;
        }
    }
    if(count == 9){
        return(1);
    }
    return(0);
}

void puzzle_free(puzzle_t* p){
    /*printf("free game\n");*/
    for(int i = 0; i < 81; i++){
        free(p->rows[i/9].cells[i%9]);
    }
    free(p->rows);
    free(p->cols);
    free(p->boxs);
    free(p);
}

void puzzle_print(puzzle_t* p, int flat){
    if(flat == 1){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                printf("%d", p->rows[i].cells[j]->value);
            }
        }
        printf("\n");
    } else {
        for(int i = 0; i < 9; i++){
            // TODO Hor row break
            for(int j = 0; j < 9; j++){
                if(p->rows[i].cells[j]->value != 0){
                    printf("%d", p->rows[i].cells[j]->value);
                }
                else{
                    printf(" ");
                }
                // TODO print blanks rather then zeros
                // TODO ver col breaks
            }
            printf("\n");
        }
    }

}

