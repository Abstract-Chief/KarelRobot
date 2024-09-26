#include <check.h>
#include <internals.h>

#include "superkarel.h"


START_TEST(when_facing_north_then_return_false)
    {
        _karel.direction = NORTH;
        _karel.is_running = true;

        ck_assert_int_eq(not_facing_north(), false);
    }
END_TEST


START_TEST(when_facing_east_then_return_true)
    {
        _karel.direction = EAST;
        _karel.is_running = true;

        ck_assert_int_eq(not_facing_north(), true);
    }
END_TEST


START_TEST(when_facing_south_then_return_true)
    {
        _karel.direction = SOUTH;
        _karel.is_running = true;

        ck_assert_int_eq(not_facing_north(), true);
    }
END_TEST


START_TEST(when_facing_west_then_return_true)
    {
        _karel.direction = WEST;
        _karel.is_running = true;

        ck_assert_int_eq(not_facing_north(), true);
    }
END_TEST

Suite *suite_not_facing_north() {
    Suite *suite = suite_create("Suite not_facing_north");

    TCase *tc = tcase_create("Basic test");
    tcase_add_test(tc, when_facing_north_then_return_false);
    tcase_add_test(tc, when_facing_east_then_return_true);
    tcase_add_test(tc, when_facing_south_then_return_true);
    tcase_add_test(tc, when_facing_west_then_return_true);
    suite_add_tcase(suite, tc);

    return suite;
}
