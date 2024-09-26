set(TEST_FILES
        runner.c
        suite_facing_north.c
        suite_beepers_in_bag.c
        suite_front_is_clear.c
)

add_executable(test_karel ${TEST_FILES})
target_link_libraries(test_karel m karel ${CHECK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})