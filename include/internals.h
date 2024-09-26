#ifndef _INTERNALS_H
#define _INTERNALS_H

#include "karel.h"

#define MULTIPLIER 1000
#define MAX_WIDTH  30
#define MAX_HEIGHT 30

// global variables (application context)
extern int _step_delay;
extern struct summary _summary;
extern struct world _world;
extern struct robot _karel;


/**
 * Summary mode metadata
 */
struct summary {
    bool is_active; // flag to check, if summary is active or not
    char* type;     // type of summary (e.g. json)
};


/**
 * Types of blocks
 */
enum block {
    CLEAR = 0,
    WALL = -1
};


/**
 * World definition
 */
struct world {
    int width, height;  // world's width and height
    int **data;         // world data definition
};


/**
 * Available directions
 */
enum direction {
    EAST = 0,
    NORTH = 90,
    WEST = 180,
    SOUTH = 270
};


/**
 * Robot definition
 */
struct robot {
    int x, y;       // position
    enum direction direction;   // direction
    int steps;      // nr. of steps
    int beepers;    // nr. of beepers in bag
    bool is_running; // robot's state
    char *last_command;   // last executed command
};


/**
 * Available colors
 */
enum Colors {
    RED_ON_BLACK = 1,
    YELLOW_ON_BLACK,
    WHITE_ON_BLACK
};


/**
 * Draws scene only
 * Draws only world, without karel and state info
 */
void _draw_world();

/**
 * Render the screen
 * Renders the whole screen - with info panel and world together.
 */
void _render();

void _update(int dx, int dy);

/**
 * Exit Karel with error message
 * Karel is exited with status code EXIT_FAILURE (1). Whole behaviour
 * depends on the state, when the function is called:
 *
 * 1. when karel is not running:
 * only the error message is print out
 *
 * 2. when karel is not running and the summary is on
 * only error message is print out in the form of summary type
 *
 * 3. when karel is running and no summary is on
 * error message is written to the Karel's UI
 *
 * 4. when karel is running and summary is on
 * error message with the world representation without walls is print out in the form of summary type
 */
void _error_shut_off(const char *format, ...);


/**
 * initilaize curses, and colors if possible
 */
void _initialize();

void _deinit();

/**
 * Exports data about world and karel
 * Export is useful in summary mode only. Summary mode can be enabled
 * with environment variable LIBKAREL_SUMMARY_MODE with it's value "true".
 */
void _export_data(const char* format, ...);


/**
 * Checks if Karel is turned on and quits program, if not
 * Private function.
 */
void _check_karel_state();

#endif    /* _INTERNALS_H */

