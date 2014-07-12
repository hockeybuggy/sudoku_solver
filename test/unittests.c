/*
 *FILENAME: unittests.c
 *AUTHOR: Douglas Anderson
 */

#include <stdlib.h>
#include <malloc.h>
#include <check.h>

//Function Protoypes for tests
Suite* make_cell_suite(void);
Suite* make_group_suite(void);


int main (void){
    int number_failed;
    /*Suite *s_cell = cell_suite();*/
    /*Suite *s_group = group_suite();*/
    SRunner *sr = srunner_create(make_cell_suite());
    srunner_add_suite(sr, make_group_suite());
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

