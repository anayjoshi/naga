#ifndef ENGINE_H
#define ENGINE_H

#include "utils.h"
#include "naga.h"

/**
 * @brief Detects whether the snake collided with itself
 *
 * Determines if the (x,y) of the 'head' coincides with the (x,y) coordinate
 * of any other part of the snake.
 *
 * @param head Head of linked list representing the snake
 *
 * @return 
 */
c_bool detect_collision(const struct naga_state the_naga); 

/**
 * @brief Fills the 'live_food' global variable with new food
 */
void generate_food(void);


/**
 * @brief Adds a new element in the linked list if snake's head coincides
 * with the food. Else, the length of the linked list remains the same
 *
 * @param head_pre Pointer to the head of linked list representing the snake
 * @param food The coordinates of the location of food on the screen
 *
 * @return TRUE if the snake was able to eat food; FALSE otherwise
 */
c_bool eat_food(struct naga_part** head_ptr, struct point food);

/**
 * @brief Moves the snake in the direction provided
 *
 * Before this function is called, the (x,y) coordinates of 'head' and
 * 'head->next' coincide. This funtion simply changes the (x,y) coordinates
 * of the 'head' along the direction specified. 
 * Rounds off the coordinates of the head according to the screen size.
 *
 * @param head Head of linked list representing the snake
 * @param dir Current direction of travel of the snake
 */
void update_head(struct naga_part* head, direction_t dir);

#endif
