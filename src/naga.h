#ifndef NAGA_H
#define NAGA_H

#include "utils.h"

/**
 * @brief represents a body part of the naga. Naga is represented
 * by a linked list of naga_part
 */
struct naga_part {
    struct point pos;
    struct naga_part* next;
};

/**
 * @brief The variables which define the state of the naga
 */
struct naga_state {
    direction_t current_dir;
    direction_t prev_dir;
    struct naga_part* head;
};


/**
 * @brief  Initializes the_naga global variable
 *
 */
void init_naga();

#endif
