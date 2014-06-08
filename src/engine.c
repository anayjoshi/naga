#include <stdlib.h>
#include <stdio.h>
#include "engine.h"
#include "naga.h"
#include "config.h"

extern struct naga_state the_naga;
extern struct point live_food;
extern uint16_t screen_width;
extern uint16_t screen_height;


c_bool detect_collision(const struct naga_state naga) 
{
    struct naga_part* p;
    c_bool collided = False;
    p = naga.head->next;
    while(p!=NULL) 
    {
        if(p->pos.x == naga.head->pos.x && p->pos.y == naga.head->pos.y) 
        {
            collided = True;
        }
    p = p->next;
    }
    return collided;
}

void generate_food(void)
{
    live_food.x = 1 + rand()%(screen_width-2);
    live_food.y = 1 + rand()%(screen_height-2);
}


c_bool eat_food(struct naga_part** head_ptr, struct point food)
{
    c_bool food_ate = False;
    struct naga_part* q = malloc(sizeof(struct naga_part));
    q->pos.x = (*head_ptr)->pos.x;
    q->pos.y = (*head_ptr)->pos.y;
    q->next = (*head_ptr);
    (*head_ptr) = q;

    if((*head_ptr)->pos.x == food.x && (*head_ptr)->pos.y == food.y)
    {
        food_ate = True;
    }
    else 
    {
        struct naga_part* p_prev;
        struct naga_part* p = (*head_ptr)->next;
        while(p->next!=NULL) 
        {
            p_prev = p;
            p = p->next;
        }
        free(p);
        p_prev->next = NULL;
    }
    return food_ate;
}

void update_head(struct naga_part* head, direction_t dir)
{
    switch(dir) 
    {
        case(WEST): 
            {
                head->pos.x--; 
                if(head->pos.x == 0) 
                {
                    head->pos.x = screen_width-1; 
                }
                break;
            }
        case(EAST): 
            {
                head->pos.x++; 
                if(head->pos.x == screen_width) 
                {
                    head->pos.x = 1; 
                }
                break;
            }
        case(NORTH): 
            {
                head->pos.y--; 
                if(head->pos.y == 0) 
                {
                    head->pos.y = screen_height-1; 
                }
                break;
            }
        case(SOUTH): 
            {
                head->pos.y++; 
                if(head->pos.y == screen_height) 
                {
                    head->pos.y = 1;  
                }
                break;
            }

    }
}
