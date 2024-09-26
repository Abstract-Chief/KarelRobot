#ifndef _SUPERKAREL_H
#define	_SUPERKAREL_H

#include <stdio.h>
#include <stdbool.h>

#include "karel.h"

// *************************************** Sensors
/**
 * Checks, if there are no beepers present at the corner
 * @return true, if there are no beepers, false otherwise
 */
bool no_beepers_present();


/**
 * Checks, if there are no beepers in the bag
 * @return true, if there are no beepers, false otherwise
 */
bool no_beepers_in_bag();


/**
 * Checks, if the front of Karel is not clear to go
 * @return true if it is not clear, false otherwise
 */
bool front_is_blocked();


/**
 * Checks, if the corner on the left side of Karel is clear to go
 * @return true if it is clear, false otherwise
 */
bool left_is_clear();


/**
 * Checks, if the corner on the left side of Karel is not clear to go
 * @return true if it is not clear, false otherwise
 */
bool left_is_blocked();


/**
 * Checks, if the corner on the right side of Karel is clear to go
 * @return true if it is clear, false otherwise
 */
bool right_is_clear();


/**
 * Checks, if the corner on the right side of Karel is not clear to go
 * @return true if it is not clear, false otherwise
 */
bool right_is_blocked();


/**
 * Checks, if Karel is not facing north
 * @return true, if yes, false otherwise
 */
bool not_facing_north();


/**
 * Checks, if Karel is facing east
 * @return true, if yes, false otherwise
 */
bool facing_east();


/**
 * Checks, if Karel is not facing east
 * @return true, if yes, false otherwise
 */
bool not_facing_east();


/**
 * Checks, if Karel is facing west
 * @return true, if yes, false otherwise
 */
bool facing_west();


/**
 * Checks, if Karel is not facing west
 * @return true, if yes, false otherwise
 */
bool not_facing_west();


/**
 * Checks, if Karel is facing south
 * @return true, if yes, false otherwise
 */
bool facing_south();


/**
 * Checks, if Karel is not facing south
 * @return true, if yes, false otherwise
 */
bool not_facing_south();

#endif	/* _SUPERKAREL_H */
