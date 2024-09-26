#include <check.h>
#include <stdlib.h>
#include <time.h>

Suite* suite_facing_north();
Suite* suite_beepers_in_bag();
Suite* suite_front_is_clear();


int main(int argc, char* argv[]) {
    srand((unsigned int) time(NULL));

	SRunner* runner = srunner_create(suite_facing_north());
    srunner_add_suite(runner, suite_beepers_in_bag());
    srunner_add_suite(runner, suite_front_is_clear());

	// run runner
	srunner_set_fork_status(runner, CK_NOFORK); // if segfault, test fails
	srunner_run_all(runner, CK_NORMAL);
	int number_failed = srunner_ntests_failed(runner);

	srunner_free(runner);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
