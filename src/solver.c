/*
 *FILENAME: solver.c
 *AUTHOR: Douglas Anderson
 *CREATED: 12/07/16
 *MODIFIED: 12/07/29
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "solver.h"

#define BUFFERSIZE 1024
#define DEBUG 0

int main(int argc, char* argv[]){
    int result;
    char gameStr[82];
    struct puzzle* game;
    if(argc != 2){
        printf("Usage: solver [Game String]\n");
        return(1);
    }
    strcpy(gameStr, argv[1]);
    game = malloc(sizeof(struct puzzle));
    createGame(game, gameStr);
    #if DEBUG
    printPuzzle(game);
    printf("Puzzle validity:%d \n", puzzleIsValid(game));
    printf("Puzzle completeness:%d \n", puzzleIsComplete(game));
    #endif
    result = solve(game, -1, -1);
    #if DEBUG
    printPuzzle(game);
    printf("Puzzle validity:%d \n", puzzleIsValid(game));
    printf("Puzzle completeness:%d \n", puzzleIsComplete(game));
    #else
    printPuzzleFlat(game);
    #endif
    freeGame(game);
    return(result);
}

void createGame(struct puzzle* game, char* gameStr){
    game->rows = malloc(sizeof(struct group)*9);
    game->cols = malloc(sizeof(struct group)*9);
    game->boxs = malloc(sizeof(struct group)*9);
    for(int i = 0; i < 81; i++){
        game->rows[i/9].cells[i%9] = malloc(sizeof(struct cell)); 
        game->rows[i/9].cells[i%9]->value = gameStr[i] - 48;
        /*printf("square number:%d, value:%c\n", i, gameStr[i]);*/
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            game->cols[j].cells[i] = game->rows[i].cells[j];
            game->boxs[getSquare(i,j)].cells[(i%3)*3+(j%3)] = game->rows[i].cells[j];
        }
    }
}

void freeGame(struct puzzle* game){
    /*printf("free game\n");*/
    for(int i = 0; i < 81; i++){
        free(game->rows[i/9].cells[i%9]);
    }
    free(game->rows);
    free(game->cols);
    free(game->boxs);
    free(game);
}

int solve(struct puzzle* game, int x, int y){
    int nextFree;
    if(x == -1 || y == -1){
        if(puzzleIsValid(game) == 0){
            return(0);
        }
    }
    else{
        if(moveIsValid(game, x, y) == 0){
            return(0);
        }
    }
    if(puzzleIsComplete(game) == 1){
        return(1); // The game is valid and complete
    }
    nextFree = getNextFree(game);
    if(nextFree < 0){
        return(0);
    }
    for(int i = 1; i <= 9; i++){
        game = makeMove(game, nextFree/9, nextFree%9, i);
        if(solve(game, nextFree/9, nextFree%9) == 1){
            return(1);
        }
        game = makeMove(game, nextFree/9, nextFree%9, 0); // Resets to zero
    }
    return(0);
}

int getNextFree(struct puzzle* game){
    for(int i = 0; i < 81; i++){
        if(game->rows[i/9].cells[i%9]->value == 0){
            return(i);
        } 
    }
    return(-1);
}

struct puzzle* makeMove(struct puzzle* game, int row, int col, int val){
    if(row < 0 || row > 8 || col < 0 || col > 8){
        printf("Not a valid square r:%d c:%d \n", row, col);
        return(NULL);
    }
    if(val < 0 || val > 9){
        printf("Not a valid value\n");
        return(NULL);
    }
    game->rows[row].cells[col]->value = val;
    return(game);
}

int getSquare(int x, int y){
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

int puzzleIsValid(struct puzzle* game){
    for(int i = 0; i < 9; i++){
        if(groupIsValid(&game->rows[i]) != 1){
            return(0);
        }
        if(groupIsValid(&game->cols[i]) != 1){
            return(0);
        }
        if(groupIsValid(&game->boxs[i]) != 1){
            return(0);
        }
    }
    return(1);
}

int moveIsValid(struct puzzle* game, int x, int y){
    if(groupIsValid(&game->rows[x]) != 1){
        return(0);
    }
    if(groupIsValid(&game->cols[y]) != 1){
        return(0);
    }
    if(groupIsValid(&game->boxs[getSquare(x,y)]) != 1){
        return(0);
    }
    return(1);
}

int groupIsValid(struct group* g){
    int exists[9];
    for(int i = 0; i < 9; i++){
        exists[i] = 0;
    }
    for(int i = 0; i < 9; i++){
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

int puzzleIsComplete(struct puzzle* game){
    int count = 0;
    for(int i = 0; i < 9; i++){
        if(groupIsComplete(&game->rows[i]) != 1){
            count++;
        }
    }
    if(count == 9){
        return(1);
    }
    return(0);
}

int groupIsComplete(struct group* g){
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


void printPuzzle(struct puzzle* game){
    for(int i = 0; i < 9; i++){
        // TODO Hor row break
        for(int j = 0; j < 9; j++){
            if(game->rows[i].cells[j]->value != 0){
                printf("%d", game->rows[i].cells[j]->value);
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

void printPuzzleFlat(struct puzzle* game){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d", game->rows[i].cells[j]->value);
        }
    }
    printf("\n");
}


