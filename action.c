//Celine Ho
//get action function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_action(struct bot *b, int *action, int *n) {

    struct location *forwards = b->location;
    struct bot *money = b->cash;
    
    int max_move = b->maximum_move;


    while(money > saving(b)) {
        if(nearest_seller(b) !=  0) {
            action = ACTION_MOVE:
            n = nearest_seller(b);
            
            action = ACTION_BUY;
            struct location * price = b->location->price;
            int selling = (money - saving(b)) /price;
            n = selling;
            
            char product[] = nearest_buyer(b);
            while(strcmp(forwards->commodity->name, product) != 0) {
                forwards = forwards->next;
            }
            action = ACTION_BUY;
            int buying = selling;
            n = buying;
            buying = 0;
            selling = 0;
        }
        
        int fuel_needed = b->fuel_tank_capacity - (b->fuel);
        if(b->type->LOCATION_PETROL_STATION && fuel_needed > 0) {
            fuel_bot(b);
        }
        
        action = ACTION_MOVE;
        n = max_move;
    }
    
}        


            
            
            
        


