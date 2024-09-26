#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <libintl.h>

#define _(STRING) gettext(STRING)

#include "internals.h"


// *************************************** Basic Karel's Sensors

bool beepers_in_bag() {
    _check_karel_state();
    return _karel.beepers > 0;
}

bool front_is_clear() {
    _check_karel_state();

    switch (_karel.direction) {
        case NORTH    :
            if (_karel.y + 1 >= _world.height || _world.data[_karel.y + 1][_karel.x] == WALL) {
                return false;
            }
            break;
        case SOUTH    :
            if (_karel.y - 1 < 1 || _world.data[_karel.y - 1][_karel.x] == WALL) {
                return false;
            }
            break;
        case WEST    :
            if (_karel.x - 1 < 1 || _world.data[_karel.y][_karel.x - 1] == WALL) {
                return false;
            }
            break;
        case EAST    :
            if (_karel.x + 1 >= _world.width || _world.data[_karel.y][_karel.x + 1] == WALL) {
                return false;
            }
            break;
    }

    return true;
}


bool facing_north() {
    _check_karel_state();
    return _karel.direction == NORTH;
}


bool beepers_present() {
    _check_karel_state();
    return _world.data[_karel.y][_karel.x] > 0;
}


// *************************************** Basic Karel's Primitives

void step() {
    _check_karel_state();

    if (front_is_clear()) {
        switch (_karel.direction) {
            case NORTH  :
                _karel.y += 2;
                _update(0, 1);
                break;
            case SOUTH  :
                _karel.y -= 2;
                _update(0, -1);
                break;
            case WEST   :
                _karel.x -= 2;
                _update(-1, 0);
                break;
            case EAST   :
                _karel.x += 2;
                _update(1, 0);
                break;
        }

        _karel.steps++;
        _karel.last_command = _("STEP");
        _render();
    } else {
        _error_shut_off(_("Can't move this way."));
    }
}


void turn_left() {
    _check_karel_state();

    _karel.direction += 90;
    if (_karel.direction > 270) {
        _karel.direction = EAST;
    }
    _karel.steps++;
    _karel.last_command = _("TURN LEFT");

    _update(0, 0);
    _render();
}


void turn_off() {
    _karel.last_command = _("TURN OFF");
    _render();
    _deinit();

    // if summary, then export data
    if (_summary.is_active) {
        _export_data(NULL);
    }

    // free memory
    for (size_t y = 0; y < _world.height; y++) {
        free(_world.data[y]);
    }
    free(_world.data);

    // credits
    if (!_summary.is_active) {
        printf(_("Created by miroslav.binas@tuke.sk (c)2010, 2016, 2018-2019\n"));
    }

    exit(EXIT_SUCCESS);
}


void turn_on(const char *path) {
    // check, if we are running summary mode
    char *mode = getenv("LIBKAREL_SUMMARY_MODE");
    if (mode && strcmp(mode, "true") == 0) {
        _summary.is_active = true;

        // check the type of summary mode
        char* type = getenv("LIBKAREL_SUMMARY_MODE_TYPE");
        if(type && strcmp(type, "json") == 0){
            _summary.type = type;
        }
    }

    // open file and read the world params
    FILE *fp = stdin;
    if(path != NULL){
        fp = fopen(path, "r");
        if (fp == NULL) {
            _error_shut_off(_("World file '%s' not found."), path);
        }
    }

    int row, column, count;
    char direction, block, orientation;

    if (fscanf(fp, "%d %d %d %d %c %d\n",
               &_world.width, &_world.height, &_karel.x, &_karel.y, &direction, &_karel.beepers) != 6) {
        _error_shut_off(_("The world information are not in correct format!"));
    }

    // world correction
    _world.width = _world.width * 2 - 1;
    _world.height = _world.height * 2 - 1;

    // karel position correction
    _karel.x = _karel.x * 2 - 2;
    _karel.y = _karel.y * 2 - 2;

    // check the world dimensions
    if (_world.width > MAX_WIDTH || _world.width < 1) {
        _error_shut_off(_("The world's width is outside the range [1, %d]!"),
                MAX_WIDTH);
    }

    if (_world.height > MAX_HEIGHT || _world.height < 1) {
        _error_shut_off(_("The world's height is outside the range [1, %d]!"),
                MAX_HEIGHT);
    }

    // format the direction
    switch (toupper(direction)) {
        case 'S'    :
            _karel.direction = SOUTH;
            break;
        case 'W'    :
            _karel.direction = WEST;
            break;
        case 'E'    :
            _karel.direction = EAST;
            break;
        case 'N'    :
            _karel.direction = NORTH;
            break;
        default     :
            _error_shut_off(_("Uknown Karel's direction."));
    }

    // create empty world
    _world.data = (int **) calloc(_world.height, sizeof(int *));
    for (size_t y = 0; y < _world.height; y++) {
        _world.data[y] = (int *) calloc(_world.width, sizeof(int));
    }

    // load the map description
    int line = 2;
    while (fscanf(fp, "%c", &block) != EOF) {

        switch (toupper(block)) {
            case 'W': {
                int column2, row2;

                // read the data
                if (fscanf(fp, "%d %d %c\n", &column, &row, &orientation) != 3) {
                    _error_shut_off(_("Line %d: Incorrect format."), line);
                }

                // check correct position
                if (column > _world.width || row > _world.height) {
                    _error_shut_off(_("Line %d: Wall position is outside the world!"), line);
                }

                column2 = column * 2 - 2;
                row2 = row * 2 - 2;

                // check, if the wall is correctly positioned
                if (column2 % 2 == 1 || row2 % 2 == 1) {
                    _error_shut_off(_("Wrong position."));
                }

                // set walls
                switch (toupper(orientation)) {
                    case 'E':
                        column2++;
                        break;
                    case 'W':
                        column2--;
                        break;
                    case 'N':
                        row2++;
                        break;
                    case 'S':
                        row2--;
                        break;
                    default :
                        _error_shut_off(_("Uknown wall orientation '%c' on line"
                                    " %d in world file."), orientation, line);
                }

                _world.data[row2][column2] = WALL;

                // set vertical line
                if (column2 % 2 == 1 && row2 % 2 == 0) {
                    if (row2 + 1 < _world.height) {
                        _world.data[row2 + 1][column2] = WALL;
                    }
                    if (row2 - 1 >= 0) {
                        _world.data[row2 - 1][column2] = WALL;
                    }
                } else {
                    // set horizontal line
                    if (column2 + 1 < _world.width) {
                        _world.data[row2][column2 + 1] = WALL;
                    }
                    if (column2 - 1 >= 0) {
                        _world.data[row2][column2 - 1] = WALL;
                    }
                }
                break;
            }

            case 'B': {
                if (fscanf(fp, "%d %d %d\n", &column, &row, &count) != 3) {
                    _error_shut_off(_("Line %d: Incorrect format."), line);
                }

                // check correct position
                if (column > _world.width || row > _world.height) {
                    _error_shut_off(_("Line %d: Beeper position is outside the world!"), line);
                }

                _world.data[row * 2 - 2][column * 2 - 2] = count;
                break;
            }

            default :
                _error_shut_off(_("Unknown block character %c on line %d in world file."), block, line);
        }

        line++;
    }

    // close the file and draw the scene
    fclose(fp);

    // final initialization
    _initialize();
    _karel.last_command = _("TURN ON");
    _draw_world();
    _render();

    _karel.is_running = true;
}


void put_beeper() {
    _check_karel_state();

    if (_karel.beepers > 0) {
        _world.data[_karel.y][_karel.x]++;
        _karel.beepers--;
        _karel.steps++;
        _karel.last_command = _("PUT BEEPER");
        _render();
    } else {
        _error_shut_off(_("Karel has no beeper to put at the corner."));
    }
}


void pick_beeper() {
    _check_karel_state();

    if (_world.data[_karel.y][_karel.x] > 0) {
        _world.data[_karel.y][_karel.x]--;
        _karel.beepers++;
        _karel.steps++;
        _karel.last_command = _("PICK BEEPER");
        _render();
    } else {
        _error_shut_off(_("There is no beeper at the corner."));
    }
}


// *************************************** Functions
void set_step_delay(int delay) {
    _step_delay = delay * MULTIPLIER;
}

