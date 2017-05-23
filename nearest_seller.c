//Celine Ho
//15/05/2017
//locates nearest seller to ensure that after buying the product you can sel it

#include <stdio.h>
#include <stdlib.h>

#include "trader_bot.h"


char nearest_seller(struct bot *b) {

    struct location *start = b->location;
    struct location *forwards = start;
//    struct location *backwards = start;

    char product = nearest_buyer(b);

    //finds a seller for the product the buyer is buying
    
    int seller_distance = 0;
    int seller = 0;
    int price = 0;
     
    
    while(distance == 0 || forwards != start) {
        if(strcmp(forwards->commodity->name, product) == 0) {
            printf("found seller selling %s", product);
            price = forwards->price;
            seller = 1;    
            return seller_distance;
        }
/*        if(strcmp(backwards->commodity->name, product) == 0) {
            printf("found seller selling %s", product);
            buyer = 1;
            return product;
        }
*/        forwards = forwards->next;
//        backwards = backwards->previous;
        seller_distance++;
    }

    if(seller == 0) {
        printf("No buyer selling that product: %s", product);
        return seller;
    }    
}
