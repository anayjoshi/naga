#ifndef NCURSES_WRAPPER_H
#define NCURSES_WRAPPER_H

#include "naga.h"

/**
 * @brief Wrapper around curses initialization
 */
void curses_init();

/**
 * @brief Cleans up curses so that the termnial stays sane after this program exits
 */
void curses_exit();

/**
 * @brief Wrapper around clear()
 */
void curses_clear_screen();

/**
 * @brief Wrapper around refresh()
 */
void curses_refresh();

/**
 * @brief Wrapper around mvaddch()
 *
 * @param y y coordinate on screen
 * @param x x coordinate on screen
 * @param ch character to be displayed
 */
void curses_show_char(int y, int x, int ch);
#endif
