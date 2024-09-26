#include <check.h>
#include <internals.h>

#include "karel.h"


START_TEST(when_no_block_in_front_then_return_true)
    {
        _karel.direction = NORTH;
        _karel.is_running = true;

        _world.height = 2;
        _world.width = 2;
        _world.data = NULL;

        ck_assert_int_eq(front_is_clear(), true);
    }
END_TEST


//START_TEST(when_block_in_front_then_return_false)
//    {
//        _karel.direction = NORTH;
//        _karel.is_running = true;
//
//        ck_assert_int_eq(front_is_clear(), false);
//    }
//END_TEST
//
//
//START_TEST(when_beeper_in_front_then_return_true)
//    {
//        _karel.direction = NORTH;
//        _karel.is_running = true;
//
//        ck_assert_int_eq(front_is_clear(), true);
//    }
//END_TEST
//
//
//START_TEST(when_on_edge_then_return_false)
//    {
//        _karel.direction = NORTH;
//        _karel.is_running = true;
//
//        ck_assert_int_eq(front_is_clear(), false);
//    }
//END_TEST



Suite *suite_front_is_clear() {
    Suite *suite = suite_create("Suite front_is_clear");

    TCase *tc = tcase_create("Basic test");
    tcase_add_test(tc, when_no_block_in_front_then_return_true);
    suite_add_tcase(suite, tc);

    return suite;
}
