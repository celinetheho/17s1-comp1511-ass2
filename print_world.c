//Celine Ho
//9/05/2017
//prints a description of all the locations in the bots world

#include <stdio.h>
#include <stdlib.h>

#include "trader_bot.h"

#define LOCATION_START            0
#define LOCATION_SELLER           1
#define LOCATION_BUYER            2
#define LOCATION_PETROL_STATION   3
#define LOCATION_DUMP             4
#define LOCATION_OTHER            5


void print_world(struct bot *b) {

    struct location *current = b->location;
    struct location *start = current;

    int count = 0; //to print first location since no NULL pointer in circular linked list

    while(current != start || count == 0) {
        if(current->type == LOCATION_START) {
            printf("%s: start\n", current->name);
        }
        if(current->type == LOCATION_SELLER) {
            printf("%s: will sell %d units of %s for $%d \n",current->name, current->quantity,current->commodity->name, current->price );
        }
        if(current->type == LOCATION_BUYER) {
            printf("%s: will buy %d units of %s for $%d \n",current->name, current->quantity,current->commodity->name, current->price );
        }
        if(current->type == LOCATION_PETROL_STATION) {
            printf("%s: Petrol station %d units of available fuel for $%d\n", current->name, current->quantity, current->price);
        }
        if(current->type == LOCATION_DUMP) {
            printf("%s: dump\n", current->name);
        }
        if(current->type == LOCATION_OTHER) {
            printf("%s: other\n", current->name);
        }    
        current = current->next;
        count++;
      
    }

}
