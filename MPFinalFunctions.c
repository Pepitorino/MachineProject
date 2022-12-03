#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TypeCosting.c"

struct Order 
{
    int main;
    int side;
    int drink;
};

void randomize (struct Order *order)
{
    order->main=rand()%4+1;
    order->drink=rand()%4+1;
    order->side=rand()%4+1;
}

int compare (struct Order order1, struct Order order2)
{
    if (order1.main!=order2.main) return 0;
    if (order1.side!=order2.side) return 0;
    if (order1.drink!=order2.drink) return 0;
    return 1; 
}

float subtotal (struct Order order, struct Order orderDay)
{
    float subtotal = mainCost(order.main)+sideCost(order.side)+drinkCost(order.drink);

    if (compare(order, orderDay))
        return subtotal-subtotal*0.15;
    return subtotal;
}

void order (struct Order* orders, struct Order orderDay, int* ordernum);
void displayMealset (struct Order order);
float receipt (struct Order* orders, struct Order orderDay, int* ordernum);

void order (struct Order* orders, struct Order orderDay, int* ordernum)
{
    int i;
    float total;
    char ans;

    do {
        printf("\n\nHow many orders would you like? (Maximum of 3)\t");
        scanf("%d", ordernum);
        fflush(stdin);

        if (*ordernum<0||*ordernum>3) printf("Invalid amount");

    } while (*ordernum<0||*ordernum>3);

    do {
        printf("\nProceed to ordering? (Y/N) ");
        scanf("%c", &ans);
        fflush(stdin);

        if (ans=='n'||ans=='N') *ordernum=0;
        if (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n') printf("Invalid option.\n");
    } while (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n');

    for (i=1; i<=*ordernum; i++){
        printf("\nOrder %d:", i);

        do {
            printf("\n\nChoose an option:");
            printf("\n\t1. Choose Mealset");
            printf("\n\t2. Mealset of the Day");
            printf("\n\t3. Randomize Mealset\n\nOption: ");
            scanf(" %c", &ans);
            fflush(stdin);
            
            if (ans>'3'||ans<'1') printf("\nInvalid option.\n");
        } while (ans>'3'||ans<'1');

        switch (ans){
            case '3':
                randomize(&orders[i]);
                displayMealset(orders[i]);
                break;
            case '2':
                orders[i]=orderDay;
                displayMealset(orders[i]);
                break;
            case '1':
                printf("\n\tMain:\t");
                scanf(" %d", &orders[i].main);
                fflush(stdin);
                printf("\t\t%s", mainType(orders[i].main));
                if (orders[i].main>4||orders[i].main<0) orders[i].main=0;
                printf("\t\tP%.2f", mainCost(orders[i].main));

                printf("\n\tSide:\t");
                scanf(" %d", &orders[i].side);
                fflush(stdin);
                printf("\t\t%s", sideType(orders[i].side));
                if (orders[i].side>4||orders[i].side<0) orders[i].side=0;
                printf("\tP%.2f", sideCost(orders[i].side));

                printf("\n\tDrink:\t");
                scanf(" %d", &orders[i].drink);
                fflush(stdin);
                printf("\t\t%s", drinkType(orders[i].drink));
                if (orders[i].drink>4||orders[i].drink<0) orders[i].drink=0;
                printf("\t\tP%.2f", drinkCost(orders[i].drink));
                break;
        }

        if (compare(orders[i], orderDay)){
            printf("\n\n\tMealset of the Day Discount: -15%%");
        }

        printf("\n\nSubtotal: P%.2f", subtotal(orders[i], orderDay));

        do {
            printf("\n\nIs this order correct? (Y/N)");
            printf("\nOption: ");
            scanf(" %c", &ans);
            fflush(stdin);

            if (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n') printf("\nInvalid option.");
        } while (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n');

        if (ans=='n'||ans=='N'){
            do {
                printf("\nWould you like to\n1. Restart Order\n2. Cancel\nOption: ");
                scanf(" %c", &ans);
                fflush(stdin);

                if (ans=='1'){
                    i--;
                }
                else if (ans=='2'){
                    do {
                        printf("\nWould you like to\n1. Cancel this order\n2. Cancel all orders\nOption: ");
                        scanf(" %c", &ans);
                        if (ans=='1'){
                            i--;
                        }
                        else if(ans=='2'){
                            *ordernum=0;
                        }
                        else printf("Invalid option.");
                    } while (ans!='1'&&ans!='2');
                }
                else printf("\nInvalid option.\n");

            } while(ans!='1'&&ans!='2');
        }

        //cancel order then go into which type of cancel
    }

    receipt(orders, orderDay, ordernum);
}

void displayMealset (struct Order order)
{
    printf("\nMain: %d", order.main);
    printf("\n\t%s", mainType(order.main));
    printf("\t\tP%.2f", mainCost(order.main));

    printf("\nSide: %d", order.side);
    printf("\n\t%s", sideType(order.side));
    printf("\tP%.2f", sideCost(order.side));

    printf("\nDrink: %d", order.drink);
    printf("\n\t%s", drinkType(order.drink));
    printf("\t\tP%.2f", drinkCost(order.drink));
    
    return;
}

float receipt(struct Order* orders, struct Order orderDay, int *ordernum)
{
    int i;
    float total;

    for (i=1; i<=*ordernum; i++){
        printf("\nOrder #%d:", i);
        displayMealset(orders[i]);
        if(compare(orders[i], orderDay)){
            printf("\n\nMealset of the Day Discount: -15%%");
        }
        printf("\n\nSubtotal: P%.2f\n", subtotal(orders[i], orderDay));
        total += subtotal(orders[i], orderDay);
    }
    printf("\n\nTotal amount: P%.2f", total);
}

