#include <unistd.h>
#include <curses.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "naga.h"
#include "keypress.h"
#include "render.h"
#include "engine.h"
#include "curses_wrapper.h"


struct naga_state the_naga;
uint16_t current_score;
c_bool game_on;
struct point live_food;
uint16_t screen_width;
uint16_t screen_height;

void* display_thread(void*); //the thread responsible for the movement of the naga

int main()
{
    curses_init();
    game_on = True;
    current_score = 0;
    getmaxyx(stdscr, screen_height, screen_width);
    init_naga();
    generate_food();

    pthread_t display_thread_id;
    pthread_create(&display_thread_id, NULL, &display_thread, NULL); 
    // This sleep is needed to avoid garbage display on screen when the game starts
    usleep(10000);

    while (game_on == True) 
    {
        int c = getch();
        process_keypress(c); // the user input keys decide the updated direction of the naga
    }
    curses_exit();
    return 0;
}

/**
 * @brief A thread which handles the rendering of the screen
 *
 * This thread displays stuff on the screen and then goes to sleep for a few microseconds. 
 * It is used so that the naga should keep moving in the current direction with any effort from the user
 * @param unused
 *
 * @return 
 */
void* display_thread(void* unused) 
{
  while(game_on == True) 
    {
        c_bool collided = detect_collision(the_naga);
        if(collided == True)
        {
            game_on = False;
        }
        c_bool food_ate = eat_food(&the_naga.head, live_food);
        if (food_ate == True)
        {
            current_score++;
            generate_food();
        }
        update_head(the_naga.head, the_naga.current_dir); 
        render_screen(the_naga);
        curses_refresh();
/*
depending upon the direction of the naga, the sleep time is changed. This is done because the size of the screen is not uniform. If the below mentioned code is not added, then the naga appears to move in y direction very quickly
*/
        if(the_naga.current_dir == WEST | the_naga.current_dir == EAST)
        {
            usleep(SLEEP_WHEN_TRAVELLING_WEST);
        }
        else
        {
            usleep(SLEEP_WHEN_TRAVELLING_EAST);
        }
    }
    return NULL;
}
