//Celine Ho
//15/05/2017
//locates nearest buyer

#include <stdio.h>
#include <stdlib.h>

#include "trader_bot.h"

#define LOCATION_START            0
#define LOCATION_SELLER           1
#define LOCATION_BUYER            2
#define LOCATION_PETROL_STATION   3
#define LOCATION_DUMP             4
#define LOCATION_OTHER            5

#define ACTION_MOVE           0
#define ACTION_BUY            1
#define ACTION_SELL           2
#define ACTION_DUMP           3


int nearest_buyer(struct bot *b) {

    struct location *start = b->location;
    struct location *forwards = start;
    struct location *backwards = start;

    int distance = 0;

    while(forwards != start || distance == 0) {
        if(forwards->type == LOCATION_BUYER) {
            printf("%s: %s", forwards->name, forwards->commodity->name);
            return distance;
        }
        if(backwards->type == LOCATION_BUYER) {
            printf("%s: %s", backwards->name, backwards->commodity->name);
            return -(distance);
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        distance++;
    }

}
