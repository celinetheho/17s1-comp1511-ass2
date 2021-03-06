//Celine Ho
//15/05/2017
//locates nearest buyer that is buying what the nearest seller is selling

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trader_bot.h"
#include "header.h"

int nearest_buyer1(struct bot *b) {

if(b->cargo != NULL) {
    struct location *start = b->location;
    
    struct location *forwards = start;
    struct location *backwards = start;
    
    char *product_seller = b->cargo->commodity->name;
    int buyer_distance = 0;
    
    //sifts through the nearest buyers for a buyer that sells the commodity of the nearest seller
    while(forwards != start || buyer_distance == 0) {
        if(forwards->type == LOCATION_BUYER && (forwards->quantity != 0)) {
            if(strcmp(forwards->commodity->name, product_seller) == 0 && forwards->commodity != NULL) {
                return buyer_distance;
            }
        }
        if(backwards->type == LOCATION_BUYER && (backwards->quantity != 0)) {
            if(strcmp(backwards->commodity->name, product_seller) == 0 && backwards->commodity != NULL) {
                return -(buyer_distance);
            }
        }
        forwards = forwards->next;
        backwards = backwards->previous;
        buyer_distance++;
    }
}
    return 0;
}
