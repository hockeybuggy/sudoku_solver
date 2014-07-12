/*
 *FILENAME: group.h
 *AUTHOR: Douglas Anderson
 */

#include "cell.h"

typedef struct group{
    cell_t* cells[9];
} group_t;

// Returns TRUE if there are no duplicates in a group
int group_is_valid(group_t* g);

// Returns TRUE if the group is complete
int group_is_complete(group_t* g);

