//Celine Ho
//15/05/2017
//locates nearest buyer 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trader_bot.h"

char nearest_buyer(struct bot *b) {

    struct location *start = b->location;
    struct location *forwards = start;
//    struct location *backwards = start;

    int buyer_distance = 0;
    char product[];

    //locates nearest buyer and returns the product its buying
    while(forwards != start || distance == 0) {
        if(forwards->type == LOCATION_BUYER) {
            printf("buyer %s: %s", forwards->name, forwards->commodity->name);
            product = forwards->commodity->name;
            return product;
        }
/*        if(backwards->type == LOCATION_BUYER) {
            printf("buyer %s: %s", backwards->name, backwards->commodity->name);
            product = forwards->commodity->name;
            return product;
        }
*/        forwards = forwards->next;
//        backwards = backwards->previous;
        buyer_distance++;
    }
    
}
