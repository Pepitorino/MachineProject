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


/*Runs at the start, created to streamline menu creation.
Precondition: No precondition.
@return void
*/
void menu(){
        printf("Mains:");
    printf("\n-----------------------------------------");
    printf("\n|ID|Type\t\t|Price\t\t|");
    printf("\n-----------------------------------------");
    printf("\n|1 |\tChicken \t|90.00\t\t| ");
    printf("\n-----------------------------------------");
    printf("\n|2 |\tPork    \t|105.00\t\t| ");
    printf("\n-----------------------------------------");
    printf("\n|3 |\tFish    \t|120.00\t\t| ");
    printf("\n-----------------------------------------");
    printf("\n|4 |\tBeef    \t|135.00\t\t| ");
    printf("\n-----------------------------------------");

    printf("\n\nSides:");
    printf("\n-----------------------------------------");
    printf("\n|ID|Type\t\t|Price\t\t|");
    printf("\n-----------------------------------------");
    printf("\n|1 |\tSteamed Rice    \t|20.00\t| ");
    printf("\n-----------------------------------------");
    printf("\n|2 |\tShredded Corn    \t|35.00\t| ");
    printf("\n-----------------------------------------");
    printf("\n|3 |\tMashed Potatoes    \t|50.00\t| ");
    printf("\n-----------------------------------------");
    printf("\n|4 |\tSteam Vegetables    \t|65.00\t| ");
    printf("\n-----------------------------------------");

    printf("\n\nDrink:");
    printf("\n-----------------------------------------");
    printf("\n|ID|Type\t\t|Price\t\t|");
    printf("\n-----------------------------------------");
    printf("\n|1 |\tMineral Water\t|25.00\t\t| ");
    printf("\n-----------------------------------------");
    printf("\n|2 |\tIced Tea    \t|35.00\t\t| ");
    printf("\n-----------------------------------------");
    printf("\n|3 |\tSoda    \t|45.00\t\t| ");
    printf("\n-----------------------------------------");
    printf("\n|4 |\tFruit Jucie    \t|55.000\t\t| ");
    printf("\n-----------------------------------------\n");
}

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
    int meal1, meal2, meal3;
    int main1, main2, main3;
    int side1, side2, side3;
    int drink1, drink2, drink3;
    char option;
    printf("Hello! I am a program made to handle your order. \n");
    printf("Here's our menu!\n");
    menu();
    printf("How many meals would you like to order? ");
    scanf("%d \n", &orders);
}