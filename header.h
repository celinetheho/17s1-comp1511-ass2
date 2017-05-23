//header file for all the trader bot functions

void get_action(struct bot *b, int *action, int *n);

char nearest_seller(struct bot *b);
char nearest_buyer(struct bot *b);

int saving(struct bot *b);

int nearest_fuel(struct bot *b);
void fuel(struct bot *b, int *action, int *n);

int buy(struct bot *b, int *action, int *n);
int sell(struct bot *b, int *action, int *n)


