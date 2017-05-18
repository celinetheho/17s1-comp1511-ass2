//Celine Ho
//15/05/2017

#include <stdio.h>
#include <stdlib.h>

#include "trader_bot.h"

#define LOCATION_START            0
#define LOCATION_SELLER           1
#define LOCATION_BUYER            2
#define LOCATION_PETROL_STATION   3
#define LOCATION_DUMP             4
#define LOCATION_OTHER            5

#define ACTION_MOVE           0
#define ACTION_BUY            1
#define ACTION_SELL           2
#define ACTION_DUMP           3


char *get_bot_name(void) {
    return "Fuel Bot";
}

void get_action(struct bot *b, int *action, int *n) {

    int max_move = b->maximum_move;
    int fuel_distance = nearest_fuel(b);
    int fuel_needed = b->fuel_tank_capacity - (b->fuel);

    if(fuel_distance == 0 && fuel_needed > 0) {
        *action = ACTION_BUY;
        *n = fuel_needed;
    }
    if(fuel_distance == 0 && fuel_needed == 0) {
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
    }
    

}
