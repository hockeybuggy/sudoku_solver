/*
 *FILENAME: cell.h
 *AUTHOR: Douglas Anderson
 */

typedef struct cell{
    int value;
    void * row; // Currently unused
    void * col;
    void * box;
} cell_t;

void cell_set(cell_t* c, int value);

int cell_get(cell_t* c);

