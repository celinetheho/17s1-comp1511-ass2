//Celine Ho
//19/05/2017
//saving money for fuel

int saving(struct bot *b) {


    struct location *fuel = b->location;
    int fuel_distance = nearest_fuel(b); //make sure the bot has enough money left for fuel
    int save_fuel_distance = fuel_distance;
    int fuel_price = 0;
    int saving = 0;

    if(fuel_distance > 0) {//get price of fuel 
        while(fuel_distance != 0) {
            fuel = fuel->next;
            fuel_distance--;
        }
    }
    else {
        while(fuel_distance != 0) {
            fuel = fuel->previous;
            fuel_distance++;
        }
    fuel_price = fuel->price;
    saving = 1.5* (b->fuel_tank_capacity * (fuel_price));

    return saving;
}

