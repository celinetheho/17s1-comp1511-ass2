//Celine Ho
//13/05/2017
//buy fuel if needed when at a petrol station

//return price of fuel for savings

#include <stdio.h>
#include <stdlib.h>

#include "trader_bot.h"


char *get_bot_name(void) {
    return "Fuel Bot";
}

void fuel(struct bot *b, int *action, int *n) {

//    int max_move = b->maximum_move;
    int fuel_distance = nearest_fuel(b);
    int fuel_needed = b->fuel_tank_capacity - (b->fuel);

    if(fuel_distance == 0 && fuel_needed > 0) {
        *action = ACTION_BUY;
        *n = fuel_needed;
    }
/*    if(fuel_distance == 0 && fuel_needed == 0) {
        *action = ACTION_MOVE;
        *n = max_move;
    }
   if(fuel_distance != 0) {
        *action = ACTION_MOVE;

        if(fuel_distance > max_move) {
            *n = max_move;
        }
        else if(fuel_distance < -(max_move)) {
            *n = max_move;
        }
        else {
            *n = fuel_distance;
        }
*/    }
