
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

Suite* cell_suite(void){
    Suite* s = suite_create("Cell");

    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_cell_create);
    tcase_add_test(tc_core, test_cell_accessor);
    suite_add_tcase(s, tc_core);
    return s;
}

int main (void){
    int number_failed;
    Suite *s = cell_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

