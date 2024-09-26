cmake_minimum_required(VERSION 2.8.9)

# Set project
project("Karel the Robot C Library" C)
set(PROJECT_VERSION_MAJOR 2019)
set(PROJECT_VERSION_MINOR 2)

# for the Curses library to load
find_package(Curses REQUIRED)
set(CURSES_USE_NCURSES TRUE)

# set compiler flags
set(CMAKE_C_FLAGS  "-Wall -Werror -pedantic -std=c11 -g")
#set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# Set build features
set(CMAKE_BUILD_TYPE Debug)

# include directories
include_directories(include ${CURSES_INCLUDE_DIR})

# build targets
# karel
add_library(karel STATIC src/karel.c  src/internals.c)
#set_property(TARGET karel PROPERTY CXX_STANDARD 11)
target_link_libraries(karel ${CURSES_LIBRARIES})

# superkarel
add_library(superkarel STATIC src/karel.c src/superkarel.c src/internals.c)
#set_property(TARGET superkarel PROPERTY CXX_STANDARD 11)
target_link_libraries(superkarel ${CURSES_LIBRARIES})


# install library and header files to /usr/local/{lib,include}
install(TARGETS karel DESTINATION lib)
install(TARGETS superkarel DESTINATION lib)
install(FILES "include/karel.h" DESTINATION include)
install(FILES "include/superkarel.h" DESTINATION include)
install(DIRECTORY "doc/" DESTINATION share/doc/libkarel USE_SOURCE_PERMISSIONS
    PATTERN "CMakeLists.txt" EXCLUDE)

# add subdirectories
add_subdirectory(doc/examples)

# tests
#enable_testing()
add_subdirectory(tests)
