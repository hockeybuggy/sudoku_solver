/*
 *FILENAME: group.h
 *AUTHOR: Douglas Anderson
 */

#ifndef GROUP_H
#define GROUP_H

#include "cell.h"

typedef struct group{
    cell_t* cells[9];
} group_t;

group_t* group_create();

// Returns TRUE if there are no duplicates in a group
int group_is_valid(group_t* g);

// Returns TRUE if the group is complete
int group_is_complete(group_t* g);

void group_free(group_t* g);

#endif

