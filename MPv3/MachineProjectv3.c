#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MachineProjectv3functions.c"

typedef struct order {
    int main;
    int side;
    int drink;
}; order_T;

int main (){
    int orders, ordernum;
    order_T arr_meal[2];
    order_T mealofday;

    srand(time(NULL));
    mealofday.drink=(rand()%4+1);
    mealofday.main=(rand()%4+1);    
    mealofday.side=(rand()%4+1);

    menu();    

    return 0;
}
