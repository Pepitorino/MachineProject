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

int order(int *orders, int* main, int* side, int* drink, char option) {
    printf("\nOrder#%d", (4-*orders));
    printf("\nMain: ");
    scanf("%i", *main);
    printf("\nSide: ");
    scanf("%i", *side);
    printf("\nDrink: ");
    scanf("%i", *drink);\
    printf("\nIs this order correct (Y/N)?");
    scanf("%c", &option);
    if (option=='N') orders++;
}

int total(){
    int discount=0;
    printf("\nOrder num: ");
    printf("\n\tMain:\t<food>\t<price>");
    printf("\n\tSide:\t<food>\t<price>");
    printf("\n\tDrink:\t<food>\t<price>");
    if(discount==1) printf("\nMeal Set of the day Discount ");
    printf("\nSubtotal:\t\t");
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
    while (order>3||order<0) {
    printf("How many meals would you like to order? ");
    scanf("%d", &orders);
    if (order>3) {
        printf("\nSorry you can only order 3 or less meals!");
    }
    else if (order<0) {
        printf("\nSorry you can't order a negative amount of meals!");
    }
    }
    while (orders!=0){
        if (order==3) {
            order(orders, &main1, &side1, &drink1, option);
        }
        else if (order==2) {
            order(orders, &main2, &side2, &drink2, option);
        }
        else if (order==1) {
            order(orders, &main3, &side3, &drink3, option);
        }
        else; 
        orders--;
    }
    
}