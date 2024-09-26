#include <check.h>
#include <internals.h>
#include <stdlib.h>

#include "superkarel.h"


START_TEST(when_no_beepers_are_in_bag_then_return_true)
    {
        _karel.beepers = 0;
        _karel.is_running = true;

        ck_assert_int_eq(no_beepers_in_bag(), true);
    }
END_TEST


START_TEST(when_one_beeper_is_in_bag_then_return_false)
    {
        _karel.beepers = 1;
        _karel.is_running = true;

        ck_assert_int_eq(no_beepers_in_bag(), false);
    }
END_TEST

START_TEST(
        when_beepers_gt_one_are_in_the_bag_then_return_false)
    {
        _karel.beepers = rand() % (RAND_MAX - 1);
        _karel.is_running = true;

        ck_assert_int_eq(no_beepers_in_bag(), false);
    }
END_TEST


Suite *suite_no_beepers_in_bag() {
    Suite *suite = suite_create("Suite no_beepers_in_bag");

    TCase *tc = tcase_create("Basic test");
    tcase_add_test(tc, when_no_beepers_are_in_bag_then_return_true);
    tcase_add_test(tc, when_one_beeper_is_in_bag_then_return_false);
    suite_add_tcase(suite, tc);

    tc = tcase_create("Random Test");
    tcase_add_loop_test(tc, when_beepers_gt_one_are_in_the_bag_then_return_false,
                        1, 20);
    tcase_add_test(tc, when_no_beepers_are_in_bag_then_return_true);
    suite_add_tcase(suite, tc);

    return suite;
}
