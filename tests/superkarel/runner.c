#include <check.h>
#include <stdlib.h>
#include <time.h>

Suite* suite_not_facing_north();
Suite* suite_not_facing_east();
Suite* suite_not_facing_west();
Suite* suite_not_facing_south();
Suite* suite_facing_east();
Suite* suite_facing_west();
Suite* suite_facing_south();
Suite* suite_no_beepers_in_bag();


int main(int argc, char* argv[]) {
    srand((unsigned int) time(NULL));

	SRunner* runner = srunner_create(suite_not_facing_north());
	srunner_add_suite(runner, suite_not_facing_east());
	srunner_add_suite(runner, suite_not_facing_west());
	srunner_add_suite(runner, suite_not_facing_south());
	srunner_add_suite(runner, suite_facing_east());
	srunner_add_suite(runner, suite_facing_west());
	srunner_add_suite(runner, suite_facing_south());
	srunner_add_suite(runner, suite_no_beepers_in_bag());

	// run runner
	srunner_set_fork_status(runner, CK_NOFORK); // if segfault, test fails
	srunner_run_all(runner, CK_NORMAL);
	int number_failed = srunner_ntests_failed(runner);

	srunner_free(runner);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
