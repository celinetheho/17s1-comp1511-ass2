//Celine Ho
//15/05/2017
//locates nearest seller

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trader_bot.h"
#include "header.h"


int nearest_seller(struct bot *b) {

    struct location *start = b->location;
    struct location *forwards = start;
    struct location *backwards = start;

    int seller_distance = 0;

    //locates nearest seller
    while(forwards != start || seller_distance == 0) {
    
        if(forwards->type == LOCATION_SELLER && forwards->quantity != 0) {
            return seller_distance;
        }
            if(backwards->type == LOCATION_SELLER && backwards->quantity != 0) {
            return -(seller_distance);
        }

        forwards = forwards->next;
        backwards = backwards->previous;
        seller_distance++;
    } 
    return 0;
} 
