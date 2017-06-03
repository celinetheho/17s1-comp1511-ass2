//Celine Ho
//13/05/2017

#include <stdio.h>
#include <stdlib.h>

#include "trader_bot.h"
#include "header.h"

int nearest_fuel(struct bot *b) {

    struct location *start = b->location;
    struct location *forwards = start;
    struct location *backwards = start;

    int distance = 0;

    while(distance == 0 || forwards != start) { //to get distance at location since no NULL pointer in circular linked list
        if(forwards->type == LOCATION_PETROL_STATION && (b->location->quantity != 0)) {
            return distance;
        }
        if(backwards->type == LOCATION_PETROL_STATION && (b->location->quantity != 0)) {
            return -(distance);
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        distance++;
    }
    return 0;
}
