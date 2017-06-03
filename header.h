//header file for all the trader bot functions

#include "trader_bot.h"

char *get_bot_name(void);
void get_action(struct bot *b, int *action, int *n);

int nearest_seller(struct bot *b);
int nearest_buyer(struct bot *b);

int nearest_buyer1(struct bot *b);

int saving(struct bot *b);

int nearest_fuel(struct bot *b);



