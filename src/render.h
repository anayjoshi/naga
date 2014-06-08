#ifndef RENDER_H
#define RENDER_H

#include "config.h"

/**
 * @brief The root function which renders the entire screen
 *
 * Clears the screen and then renders the boundary, score, food and the snake
 * This function uses global variables to get the latest values of relevant variables
 * (namely current_score, live_food and the_naga)
 */
void render_screen();

#endif
