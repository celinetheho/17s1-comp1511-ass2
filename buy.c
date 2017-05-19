//Celine Ho
//18/05/2017
//function for buying goods

int buy(struct bot *b, int *action, int *n) {


    struct location *loc = b->location;
    int distance = nearest_seller(b);
 
    if(distance > 0) {//move the bot to the seller  
        while(distance != 0) {
            loc = loc->next;
            distance--;
        }
    }
    else {
        while(distance != 0) {
            loc = loc->previous;
            distance++;
        }
    struct location *price = loc->price; //get the price of the goods

    double cash = b->cash - saving(b);
    *n = cash/price;
    *action = ACTION_BUY;

    



    

