//Celine Ho
//get action function
//20/05/2017


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"
#include "trader_bot.h"

char *get_bot_name(void) {
    return "a bot";
}

void get_action(struct bot *b, int *action, int *n) {

    //bot location
    struct location *bot_loc = b->location;
    
    //if the bot has no cargo it will go to the nearest seller
    if(b->cargo == NULL && bot_loc->type != LOCATION_SELLER) {
        *action = ACTION_MOVE;
        *n = nearest_seller(b);
    } 
    
    //if its a seller it will buy commodity
    if(bot_loc->type == LOCATION_SELLER && b->cargo == NULL) {
        *action = ACTION_BUY; 
        *n = (b->cash - saving(b))/(b->location->price);
    }
    
    if(bot_loc->type == LOCATION_SELLER && b->cargo != NULL) {
        *action = ACTION_MOVE;
        *n = nearest_buyer(b);
    }          
    struct cargo *cargo = b->cargo;

    //if its a buyer it will sell commodity
    if(b->location->type == LOCATION_BUYER && b->cargo != NULL) {
///        while(cargo->commodity->name != b->location->commodity->name) {
//            cargo = cargo->next;           
//        }
        *action = ACTION_SELL;
        *n = cargo->quantity; 
    }
       
    //buying fuel    
    int fuel_needed = b->fuel_tank_capacity - (b->fuel);
    int fuel_limit = b->fuel_tank_capacity/2;
    
        
    if(fuel_needed >= fuel_limit && bot_loc->type != LOCATION_PETROL_STATION) {
        *action = ACTION_MOVE;
        *n = nearest_fuel(b);
    }
    if(bot_loc->type == LOCATION_PETROL_STATION && fuel_needed != 0) {
        *action = ACTION_BUY;
        *n = fuel_needed;
    }  
    
}
  
