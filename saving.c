//Celine Ho
//19/05/2017
//saving money for fuel

#include "trader_bot.h"
#include "header.h"

int saving(struct bot *b) {

    struct location *loc = b->location;
    int fuel_distance = nearest_fuel(b); //make sure the bot has enough money left for fuel
    int save_fuel_distance = fuel_distance;
    int saving = 0;

    if(fuel_distance > 0) {//get price of fuel 
        while(fuel_distance != 0) {
            loc = loc->next;
            fuel_distance--;
        }
    }
    else {
        while(fuel_distance != 0) {
            loc = loc->previous;
            fuel_distance++;
        }
    }
        
    int fuel_price = loc->price;
    saving = 1.5* (b->fuel_tank_capacity * (fuel_price));

    return saving;
}

