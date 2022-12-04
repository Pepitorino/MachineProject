#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TypeCosting.c"

/*Declaration of structure to make code more modular and concise.
struct Order stores a main, side, and drink id.
To get type and cost of a certain item, use the functions found in TypeCosting.c.
*/
struct Order 
{
    int main;
    int side;
    int drink;
};

/*Randomizes an Order that is passed into it.
Precondition: No precondition.
@param order is a pointer to an order of type struct Order.
@return void
*/
void 
randomize (struct Order* order)
{
    order->main=rand()%4+1;
    order->drink=rand()%4+1;
    order->side=rand()%4+1;
}

/*Used to compare two orders that are passed into it.
If the orders are the same, returns 1(true), if not returns 0(false).
Mainly used to check if an order is the same as the "Mealset of the Day".
Precondition: No precondition
@param order1 is an order to be comapred
@param order2 is an order to be compared
@return 1 if true, 0 if false
*/
int 
compare (struct Order order1, struct Order order2)
{
    if (order1.main!=order2.main) return 0;
    if (order1.side!=order2.side) return 0;
    if (order1.drink!=order2.drink) return 0;
    return 1; 
}

/*Displays an order with type and cost to the user.
Precondition: No precondition.
@param order is the order to be displayed
@return void
*/
void 
displayMealset (struct Order order)
{
    printf("\nMain: %d", order.main);
    printf("\n\t%s", mainType(order.main));
    printf(" P%.2f", mainCost(order.main));

    printf("\nSide: %d", order.side);
    printf("\n\t%s", sideType(order.side));
    printf(" P%.2f", sideCost(order.side));

    printf("\nDrink: %d", order.drink);
    printf("\n\t%s", drinkType(order.drink));
    printf(" P%.2f", drinkCost(order.drink));
    
    return;

}


/*These functions are separated as they are dependent on one or more other functions.*/
void order (struct Order* orders, struct Order orderDay, int* ordernum);
float subtotal (struct Order order, struct Order orderday);
float receipt (struct Order* orders, struct Order orderDay, int* ordernum);

/*Function used to take orders.
Precondition: No precondition
@param orders is a pointer to an array of type struct Order that will store the order IDs
@param orderDay is the Mealset of the Day
@param ordernum is a pointer to a variable that stores the number of orders the user wants to make
@return void
*/
void 
order (struct Order* orders, struct Order orderDay, int* ordernum)
{
    int i;
    float total;
    char ans;

    // Asks user how many orders they would like to order
    do {
        printf("\n\nHow many orders would you like? (Maximum of 3)\t");
        scanf("%d", ordernum);
        fflush(stdin);

        if (*ordernum<0||*ordernum>3) printf("Invalid amount");

    } while (*ordernum<0||*ordernum>3);

    // Asks user if they would like to proceed to ordering
    do {
        printf("\nProceed to ordering? (Y/N) ");
        scanf(" %c", &ans);
        fflush(stdin);

        if (ans=='n'||ans=='N') *ordernum=0;
        if (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n') printf("Invalid option.\n");
    } while (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n');

    // Main function for ordering and choosing mealset
    for (i=1; i<=*ordernum; i++){
        printf("\nOrder %d:", i);

        /*Lets user choose if they want to choose their own mealset,
                                            choose the mealset of the day or
                                            randomize their mealset*/
        do {
            printf("\n\nChoose an option:");
            printf("\n\t1. Choose Mealset");
            printf("\n\t2. Mealset of the Day");
            printf("\n\t3. Randomize Mealset\n\nOption: ");
            scanf(" %c", &ans);
            fflush(stdin);
            
            if (ans>'3'||ans<'1') printf("\nInvalid option.\n");
        } while (ans>'3'||ans<'1');

        // Customizes mealset according to the user's choice.
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

        /* Uses compare() to check if the Mealset of the Day discount is applicable
            Purely cosmetic, only used to show user that the Mealset of the Day discount is applied*/
        if (compare(orders[i], orderDay)){
            printf("\n\n\tMealset of the Day Discount: -15%%");
        }

        // Displays cost of order to user
        printf("\n\nSubtotal: P%.2f", subtotal(orders[i], orderDay));

        // Asks the user if the order is correct
        do {
            printf("\n\nIs this order correct? (Y/N)");
            printf("\nOption: ");
            scanf(" %c", &ans);
            fflush(stdin);

            if (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n') printf("\nInvalid option.\n");
        } while (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n');


        /*Asks if the user would like to restart or cancel order*/
        if (ans=='n'||ans=='N'){
            do {
                printf("\nWould you like to\n1. Restart Order\n2. Cancel\nOption: ");
                scanf(" %c", &ans);
                fflush(stdin);

                // If user would like to restart the order, i is decremented in order to keep it at the same order.
                if (ans=='1'){
                    i--;
                }

                // If user would like to cancel order, they are asked if they would like to cancel just this order or all orders.
                else if (ans=='2'){
                    do {
                        printf("\nWould you like to\n1. Cancel this order\n2. Cancel all orders\n3. Cancel current and rest of orders\nOption: ");
                        scanf(" %c", &ans);
                        fflush(stdin);

                        /* If user would like to cancel just that order, 
                        they are asked if they would like to proceed 
                        to the next order or restart current order*/
                        if (ans=='1'){
                            if (i<*ordernum) {
                                do {
                                printf("\nWould you like to\n1. Restart Order.\n2. Proceed to next order\nOption: ");
                                scanf(" %c", &ans);
                                fflush(stdin);
                                } while (ans!='1'&&ans!='2');

                                // If user would like to restart the order, i is decremented in order to keep it at the same order.
                                if (ans=='1'){
                                    i--;
                                }
                                
                                // If user would like to proceed to next order, all items in the cancelled order are set to 0(none).
                                else if (ans=='2'){
                                    printf("\nOrder #%d cancelled", i);
                                    orders[i].main=0;
                                    orders[i].side=0;
                                    orders[i].drink=0;
                                }
                                
                            }
                        }
                        /*If user would like to cancel all orders, ordernum is put to 0, 
                        this stops the other functions and options from displaying or calculating anything*/
                        else if(ans=='2'){
                            *ordernum=0;
                        }
                        
                        /*If user would like to cancel current and rest of orders, ordernum is set to i.
                        This makes it so that it proceeds straight to the receipt*/
                        else if (ans=='3'){
                            printf("\nProceeding to checkout.\n");
                            *ordernum=i;
                        }
                        else printf("Invalid option.\n");
                    } while (ans<'1'&&ans>'3');
                }
                else printf("\nInvalid option.\n");

            } while(ans<'1'&&ans>'3'); 
        }
    }

    receipt(orders, orderDay, ordernum);
}

/*This function calculates the subtotal given the order.
Precondition: No precondition
@param order is the ids of the main, side, and drink
@param orderDay is the mealset of the day, if the @param order matches this, the subtotal is discounted by 15%
@return the cost of an order*/
float 
subtotal (struct Order order, struct Order orderDay)
{
    float subtotal = mainCost(order.main)+sideCost(order.side)+drinkCost(order.drink);

    if (compare(order, orderDay))
        return subtotal-subtotal*0.15;
    return subtotal;
}

/*This function displays to the user the receipt
@param orders is the pointer to an array of struct Order
@param orderDay is the mealset of the day is an element from @param orders matches this, it displays it to the user
@param ordernum is a pointer to the variable storing the number of orders, dereferenced for the function to
        know how many times to loop the printing.
@return void
*/
void 
receipt(struct Order* orders, struct Order orderDay, int *ordernum)
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

    return total;
}

