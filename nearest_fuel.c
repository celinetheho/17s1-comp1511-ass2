//Celine Ho
//13/05/2017

#include <stdio.h>
#include <stdlib.h>

#include "trader_bot.h"

#define LOCATION_START            0
#define LOCATION_SELLER           1
#define LOCATION_BUYER            2
#define LOCATION_PETROL_STATION   3
#define LOCATION_DUMP             4
#define LOCATION_OTHER            5


int nearest_fuel(struct bot *b) {

    struct location *start = b->location;
    struct location *forwards = start;
    struct location *backwards = start;

    int distance = 0;

    while(distance == 0 || forwards != start) { //to get distance at location since no NULL pointer in circular linked list
        if(forwards->type == LOCATION_PETROL_STATION) {
            return distance;
        }
        if(backwards->type == LOCATION_PETROL_STATION) {
            return -(distance);
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        distance++;
    }
}
