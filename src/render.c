#include "render.h"
#include "utils.h"
#include <curses.h>
#include "curses_wrapper.h"
#include <stdlib.h>
#include <stdlib.h>

extern struct naga_state the_naga;
extern uint16_t current_score;
extern c_bool game_on;
extern struct point live_food;
extern uint16_t screen_width;
extern uint16_t screen_height;


/**
 * @brief Renders the bounday of the screen. 
 *
 * The dimensions of the screen are specified by screen_width and screen_height
 *
 */
static void render_boundary()
{
    uint8_t i=0;
    for(i=1; i < screen_height; i++)
    {
        curses_show_char(i,0,'|' |  COLOR_PAIR(1));
    }
    for(i=1; i < screen_height; i++)
    {
        curses_show_char(i,screen_width,'|' | COLOR_PAIR(1));
    }
    for(i=1; i < screen_width; i++)
    {
        curses_show_char(0, i, '-' | COLOR_PAIR(1));
    }
    for(i=1; i < screen_width; i++)
    {
        curses_show_char(screen_height, i, '-' | COLOR_PAIR(1));
    }
    curses_show_char(0, 0, '/' | COLOR_PAIR(1));
    curses_show_char(0, screen_width, '\\' | COLOR_PAIR(1));
    curses_show_char(screen_height, 0, '\\' | COLOR_PAIR(1));
    curses_show_char(screen_height, screen_width, '/');
}

/**
 * @brief Displays the score on the lower right corner of the screen
 *
 * The score occupies a total of 4 characters on screen, ranging from
 * screen_width - 6 to screen_width - 3 (for y = screen_height - 4)
 *
 * @param score The score to be rendered
 */
static void render_score(uint16_t score)
{
    char s[4] = {' ',' ',' ',' '};
    itos(score, s);
    curses_show_char(screen_height-2, screen_width-11, 'S' | COLOR_PAIR(1));
    curses_show_char(screen_height-2, screen_width-10, 'c' | COLOR_PAIR(1));
    curses_show_char(screen_height-2, screen_width-9, 'o' | COLOR_PAIR(1));
    curses_show_char(screen_height-2, screen_width-8, 'r' | COLOR_PAIR(1));
    curses_show_char(screen_height-2, screen_width-7, 'e' | COLOR_PAIR(1));
    curses_show_char(screen_height-2, screen_width-6, ':' | COLOR_PAIR(1));
    curses_show_char(screen_height-2, screen_width-5, ' ' | COLOR_PAIR(1));
    curses_show_char(screen_height-2, screen_width-4, s[0] | COLOR_PAIR(1));
    curses_show_char(screen_height-2, screen_width-3, s[1] | COLOR_PAIR(1));
    curses_show_char(screen_height-2, screen_width-2, s[2] | COLOR_PAIR(1));
    curses_show_char(screen_height-2, screen_width-1, s[3] | COLOR_PAIR(1));
}

/**
 * @brief Displays the food on the screen; represented by $ symbol
 *
 * @param food Specifies the coordinates of the point where food is to be rendered
 */
static void render_food(struct point food)
{
    curses_show_char(food.y, food.x, '$' | COLOR_PAIR(4));
}


/**
 * @brief Renders the snake.
 *
 * The head is represented by # symbol, and every other part of the snake is 
 * represented by * symbol
 *
 * @param head
 */
static void render_naga(struct naga_state naga)
{
    struct naga_part* p;
    curses_show_char(naga.head->pos.y, naga.head->pos.x, '#' | COLOR_PAIR(2));
    p = naga.head->next;
    while(p->next!=NULL) 
    {
        curses_show_char(p->pos.y, p->pos.x, '*' | COLOR_PAIR(3));
        p = p->next;
    }
}

void render_screen()
{
    curses_clear_screen();
    render_boundary();
    render_score(current_score);
    render_food(live_food);
    render_naga(the_naga);
    getmaxyx(stdscr, screen_height, screen_width);
    screen_width = screen_width - 1;
    screen_height = screen_height - 1;
}

