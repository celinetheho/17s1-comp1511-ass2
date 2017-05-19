//Celine Ho
//15/05/2017
//locates nearest seller

#include <stdio.h>
#include <stdlib.h>

#include "trader_bot.h"

int nearest_buyer(struct bot *b) {

    struct location *start = b->location;
    struct location *forwards = start;
    struct location *backwards = start;

    int distance = 0;

    while(forwards != start || distance == 0) {
        if(forwards->type == LOCATION_SELLER) {
            printf("%s: %s", forwards->name, forwards->commodity->name);
            return distance;
        }
        if(backwards->type == LOCATION_SELLER) {
            printf("%s: %s", backwards->name, backwards->commodity->name);
            return -(distance);
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        distance++;
    }

}
