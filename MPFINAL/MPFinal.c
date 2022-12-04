/********************************************************************
*******
This is to certify that this project is my own work, based on my personal efforts in
studying and applying the concepts learned. I have constructed the functions and
their respective algorithms and corresponding code by myself. The program was
run, tested, and debugged by my own efforts. I further certify that I have not copied
in part or whole or otherwise plagiarized the work of other students and/or persons.
Ambrosio, Carlos Felipe Q., DLSU ID#
12275964
********************************************************************
*******/

/*
Description:      Ordering System to Handle Orders
Programmed by:    Ambrosio, Carlos Felipe Q. - S11A
Last modified:    December 4, 2022
Version:          5.0
[Acknowledgements: Tim Bailey's An Introduction to the C Programming Language and Software Design, StackOverflow]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MPFinalFunctions.c"

// typedefs the struct Order to make code more concise and cleaner
typedef struct Order Order;

int main () 
{
    Order orders[3];
    Order orderDay;
    int ordernum=0; // Assigned zero, so that if an invalid input is given when asked for number of orders, it defaults to none
    char answer;

    srand(time(NULL));
    randomize(&orderDay);
    
    printf("Welcome!");

    // Main Menu
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
            receipt(orders, orderDay, &ordernum);
            break;

            case '3':
            menu();
            break;

            case '4':
            printf("\nMealset of the Day:\n");
            displayMealset(orderDay);
            printf("\n\nDiscount: 15%%");
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