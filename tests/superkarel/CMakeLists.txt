set(TEST_FILES
        runner.c
        suite_not_facing_north.c
        suite_not_facing_east.c
        suite_not_facing_west.c
        suite_not_facing_south.c
        suite_facing_east.c
        suite_facing_west.c
        suite_facing_south.c
        suite_no_beepers_in_bag.c
)

add_executable(test_superkarel ${TEST_FILES})
target_link_libraries(test_superkarel m superkarel ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})