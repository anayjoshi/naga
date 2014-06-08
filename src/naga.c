#include <stdlib.h>
#include "naga.h"
#include "stdio.h"
#include "utils.h"
#include "config.h"


extern struct naga_state the_naga;
extern uint16_t screen_width;
extern uint16_t screen_height;


void init_naga() 
{
	the_naga.current_dir = EAST;// naga is initially moving east
	the_naga.prev_dir = EAST;
    the_naga.head = malloc(sizeof(struct naga_part));
    the_naga.head->pos.x = screen_width/2;
    the_naga.head->pos.y = screen_height/2;
    the_naga.head->next = NULL;

    int i;
    struct naga_part* p = the_naga.head;
    for(i=1; i<NAGA_INITIAL_LENGTH; i++) 
    {
        p->next = malloc(sizeof(struct naga_part));
        p->next->pos.x = screen_width/2 - i;
        p->next->pos.y = screen_height;
        p= p->next;
    }
    p->next = NULL;
}

