/*
 *FILENAME: check_group.c
 *AUTHOR: Douglas Anderson
 */

#include <stdlib.h>
#include <malloc.h>
#include <check.h>
#include "../src/group.h"

START_TEST (test_group_create)
{
    group_t* g;
    g = group_create();
    ck_assert_ptr_ne(g, NULL);
    group_free(g);
}
END_TEST

Suite* make_group_suite(void){
    Suite* s = suite_create("Group");

    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_group_create);
    suite_add_tcase(s, tc_core);
    return s;
}

