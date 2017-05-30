//Celine Ho
//15/05/2017
//locates nearest buyer 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trader_bot.h"
#include "header.h"

char *nearest_buyer(struct bot *b) {

    struct location *start = b->location;
    struct location *forwards = start;
    struct location *backwards = start;

    int buyer_distance = 0;
    int buyer = 0;
    char *product;

    //locates nearest buyer and returns the product its buying
    while(forwards != start || buyer_distance == 0) {
    
        if(forwards->type == LOCATION_BUYER) {
            printf("buyer %s: %s", forwards->name, forwards->commodity->name);
            product = forwards->commodity->name;
            buyer = 1;
            return product;
        }
            if(backwards->type == LOCATION_BUYER) {
                printf("buyer %s: %s", backwards->name, backwards->commodity->name);
                product = backwards->commodity->name;
                buyer = 1;
            return product;
        }

        forwards = forwards->next;
        backwards = backwards->previous;
        buyer_distance++;
    } 
    return 0;
}  
