#include "keypress.h"
#include "utils.h"
#include "naga.h"

extern struct naga_state the_naga;
extern c_bool game_on;

/**
 * @brief Processes a keyboard press; used for changing direction of naga, or to exit the program
 *
 * @param c The key which was pressed by the user
 */
void process_keypress(int c) 
{
  switch (c) 
    {
    case('a'): 
            {
                if (the_naga.prev_dir != EAST)
                { 
                    the_naga.current_dir = WEST;
                } 
                break;
            }
    case('d'): 
            {
                if (the_naga.prev_dir != WEST)
                { 
                    the_naga.current_dir = EAST;
                } 
                break;
            }
    case('w'): 
            {
                if (the_naga.prev_dir != SOUTH)
                { 
                    the_naga.current_dir = NORTH;
                } 
                break;
            }
    case('s'): 
            {
                if (the_naga.prev_dir != NORTH)
                { 
                    the_naga.current_dir = SOUTH;
                } 
                break;
            }
    case('q'): 
            {
                game_on = False;
            }
  }
  the_naga.prev_dir = the_naga.current_dir;
}
