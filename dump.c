//Celine Ho
//4/06/2017
//returns the distance to the nearest dump


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trader_bot.h"
#include "header.h"


int nearest_dump(struct bot *b) {

    struct location *start = b->location;
    struct location *forwards = start;
    struct location *backwards = start;

    int dump_distance = 0;

    //locates nearest dump
    while(forwards != start || dump_distance == 0) {
    
        if(forwards->type == LOCATION_DUMP) {
            printf("dump %s", forwards->name);
            return dump_distance;
        }
            if(backwards->type == LOCATION_DUMP) {
            printf("dump %s \n", backwards->name);
            return -(dump_distance);
        }

        forwards = forwards->next;
        backwards = backwards->previous;
        dump_distance++;
    } 
    return 0;
} 
