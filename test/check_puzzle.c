/*
 *FILENAME: check_puzzle.c
 *AUTHOR: Douglas Anderson
 */

#include <stdlib.h>
#include <malloc.h>
#include <check.h>
#include "../src/puzzle.h"

#define PUZZLE_STR "200000060000075030048090100000300000300010009000008000001020570080730000090000004"

START_TEST (test_puzzle_create)
{
    puzzle_t* p;
    p = puzzle_create(PUZZLE_STR);
    ck_assert_ptr_ne(p, NULL);
    puzzle_free(p);
}
END_TEST

Suite* make_puzzle_suite(void){
    Suite* s = suite_create("Puzzle");

    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_puzzle_create);
    suite_add_tcase(s, tc_core);
    return s;
}

