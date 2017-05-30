//Celine Ho
//get action function



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"
#include "trader_bot.h"

void get_action(struct bot *b, int *action, int *n) {

    struct location *forwards = b->location;
    
    int money = b->cash;   
    int max_move = b->maximum_move;


    while(money > saving(b)) {
        if(nearest_seller(b) !=  0) {
            *action = ACTION_MOVE;
            *n = nearest_seller(b);            
            *action = ACTION_BUY;
            
            int price = b->location->price;
            int quantity_buying = (money - saving(b)) /price;
            *n = quantity_buying;
            
            char *product_buying = nearest_buyer(b);
            char *product_selling = forwards->commodity->name;
          
            while(strcmp(product_buying, product_selling) != 0) {
                forwards = forwards->next;
            }
            *action = ACTION_BUY;
            int buying = quantity_buying;
            *n = buying;
            buying = 0;
            quantity_buying = 0;
        }
        
        int fuel_needed = b->fuel_tank_capacity - (b->fuel);
        double fuel_limit = b->fuel/3;
        
        if((b->location->type == LOCATION_PETROL_STATION && fuel_needed > 0) || fuel_needed > fuel_limit) {
            *action = ACTION_BUY;
            *n = fuel_needed;
        }
        
        *action = ACTION_MOVE;
        *n = max_move;
    }
    
}        


            
            
            
        


