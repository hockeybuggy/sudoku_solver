/*
 *FILENAME: check_cell.c
 *AUTHOR: Douglas Anderson
 */

#include <stdlib.h>
#include <malloc.h>
#include <check.h>
#include "../src/cell.h"

START_TEST (test_cell_create)
{
    cell_t* c;
    c = cell_create();
    ck_assert_int_eq(cell_get(c), 0);
    cell_free(c);
}
END_TEST

START_TEST (test_cell_accessor)
{
    cell_t* c;
    c = cell_create();
    ck_assert_int_eq(cell_get(c), 0);
    cell_set(c, 4);
    ck_assert_int_eq(cell_get(c), 4);
    cell_free(c);
}
END_TEST

Suite* make_cell_suite(void){
    Suite* s = suite_create("Cell");

    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_cell_create);
    tcase_add_test(tc_core, test_cell_accessor);
    suite_add_tcase(s, tc_core);
    return s;
}

