//Celine Ho
//30/5/2017

#include "trader_bot.h"
#include "header.h"

char match_comm_and_buyer(struct bot *b) {

    char comm = b->cargo->commodity;

    if(b->location == LOCATION_SELLER) {
        while(comm->name != b->location->commodity->name) {
            comm = comm->next;           
        }
        if(comm->name == b->location->commodity->name) {
            return comm->name;         
        }
    } 
    
    return 0;
} 
