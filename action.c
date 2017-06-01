//Celine Ho
//get action function



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"
#include "trader_bot.h"

char *get_bot_name(void) {
    return "Fuel Bot";
}

void get_action(struct bot *b, int *action, int *n) {

    //bot location
    struct location *bot_loc = b->location;
    
    int money = b->cash;   
    int max_move = b->maximum_move;
    int quantity_buy = 0;
    int price = b->location->price;


    while(money > saving(b)) {
        //locates nearest seller and buys commodity
        if(nearest_seller(b) !=  0) {
            //moves to nearest seller
            *action = ACTION_MOVE;
            *n = nearest_seller(b); 
            
            //buys commodity                             
            price = b->location->price;
            
            //free items???
            if(price == 0) {
                *action = ACTION_BUY;
                *n = 100; //
            } else {
                *action = ACTION_BUY;  
                quantity_buying = (money - saving(b))/price;
                *n = quantity_buying;
            }   
        } else {
            *action = ACTION_BUY;
            price = b->location->price;
            quantity_buying = (money - saving(b))/price;
        }
    }
                        
          
    //what i want to sell          
    char *product_selling = nearest_buyer(b);
    //product that the seller is selling
    char *product_buyer = forwards->commodity->name;
          
    while(strcmp(product_selling, product_buyer) != 0) {
        bot_loc = bot_loc->next;
    }
        *action = ACTION_BUY;
        int buying = quantity_buying;
        *n = buying;
            
        //reset 
        buying = 0;
        quantity_buying = 0;

    //sellling commodity at a buyer
    char comm = b->cargo->commodity;

    if(b->location == LOCATION_SELLER) {
        while(comm->name != b->location->commodity->name) {
            comm = comm->next;           
        }
        if(comm->name == b->location->commodity->name) {
            return comm->name;         
        }
    } 

          
    //buying fuel    
    int fuel_needed = b->fuel_tank_capacity - (b->fuel);
    int fuel_limit = b->fuel/3;
        
    if((b->location->type == LOCATION_PETROL_STATION && fuel_needed > 0) || fuel_needed > fuel_limit) {
        *action = ACTION_BUY;
        *n = fuel_needed;
    }
        
    *action = ACTION_MOVE;
    *n = max_move;
    
}
         



