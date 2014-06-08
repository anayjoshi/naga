#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

/**
 * @brief  Converts integer into string
 *
 * @param num Input integer
 * @param s Pointer to a character array which would eventually contain the output string
 */
void itos(const unsigned int num, char* s);

/**
 * @brief Represents a point on the screen
 */
struct point {
    uint8_t x;
    uint8_t y;
};

/**
 * @brief Used to represent the direction of the snake
 */
typedef enum direction_t {
	WEST = 1,
	EAST = 2,
	NORTH = 3,
	SOUTH = 4
} direction_t;

/**
 * @brief bool variable
 */
typedef enum {
    True,
    False
} c_bool;


#endif
