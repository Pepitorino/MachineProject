#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MPFinalFunctions.c"

typedef struct Order Order;

int main () 
{
    Order orders[3];
    Order orderDay;
    int ordernum=1;
    int i; 
    char answer;

    srand(time(NULL));
    randomize(&orderDay);
    
    printf("Welcome!");

    while (answer!='5')
    {
        printf("\n\n1. New Order");
        printf("\n2. View Previous Order Receipt");
        printf("\n3. View Menu");
        printf("\n4. View Mealset of the Day");
        printf("\n5. Exit");

        printf("\n\nSelect what you would like to do: ");

        scanf(" %c", &answer);
        fflush(stdin);

        switch (answer){
            case '1':
            order(orders, orderDay, &ordernum);
            break;

            case '2':
            for (i=1;i<=ordernum;i++){
                printf("Order #%d:", i);
                displayMealset(orders[i]);
                printf("\n\n");
                sleep(1);
            }
            receipt(orders, orderDay, &ordernum);
            break;

            case '3':
            menu();
            break;

            case '4':
            printf("\nMealset of the Day:\n");
            displayMealset(orderDay);
            printf("\n\nDiscount: 15%%");
            sleep(3);
            break;

            case '5':
            printf("\nHave a nice day!");
            break;

            default:
            printf("\nInvalid Option\n");
        }
    }

    return 0;
}