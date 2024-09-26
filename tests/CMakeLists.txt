# idea stolen from: https://github.com/vndmtrx/check-cmake-example

find_package (Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(CHECK REQUIRED check)


# Since Check uses Threads to paralelize the tests, it's mandatory
# add pthread as a dependency, alongside the Check libraries.
#add_executable(test_karel test_sample.c)
#add_executable(test_superkarel test_sample.c)
#add_executable(test_internals test_sample.c)
#target_link_libraries(test_sample sample ${CHECK_LIBRARIES} pthread)


# Aditional Valgrind test to check memory leaks in code
#include(FindValgrind)

#add_custom_target(valgrind_tests
#        COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:tests>
#        DEPENDS test_sample
#        )

add_subdirectory(karel)
add_subdirectory(superkarel)