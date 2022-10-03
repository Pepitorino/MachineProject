/*
Description: This program handles orders.
Programmed by: Ambrosio, Carlos Felipe Q. S11A
Last modified: 
Version: 0.01
[Acknowledgements: <list of sites or borrowed libraries and sources>]
*/  

#include <stdio.h>

/* <Description of function>
Precondition: <precondition /
assumption>
@param <name> <purpose>
@return <description of returned result>
*/


int total(){
    printf("\nOrder num: ");
    printf("\n\tMain:\t<food>\t<price>");
    printf("\n\tSide:\t<food>\t<price>");
    printf("\n\tDrink:\t<food>\t<price>");
    if(discount==1) printf("\nMeal Set of the day Discount ");
    printf("\nSubtotal:\t\t%d")
}

int main (){
    int orders, i;
    float meal1, meal2, meal3;
    int *ptr_orders=&orders;
    printf("Hello! I am a program made to handle your order. \n");
    printf("Here's our menu!\n");
    printf("How many meals would you like to order? ");
    scanf("%d \n", &orders);
    while (orders!=0) {
        printf("\nMain:");
        printf("\nSide:");
        printf("\nDrink:");
        printf("\nIs this meal set order correct(Y/N)?");

    }
}
