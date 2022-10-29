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

return order(int* orders, int* main, int* side, int* drink) {
    char option;
    int m, s, d;
    printf("\nOrder#%d", (*orders));
    printf("\nMain: ");
    scanf("%i", &m);
    printf("\nSide: ");
    scanf("%i", &s);
    printf("\nDrink: ");
    scanf("%i", &d);
    printf("\nIs this order correct (Y/N)?");
    scanf(" %c", &option);
    *main = m;
    *side = s;
    *drink = d;
    if (option=='Y') {
        *orders+=1;
    }
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
    int orders=0, i;
    int main1, main2, main3;
    int side1, side2, side3;
    int drink1, drink2, drink3;
    int* ptr_main1=&main1, ptr_main2=&main2, ptr_main3=&main3;
    int* ptr_side1=&side1, ptr_side2=&side2, ptr_side3=&side3;
    int* ptr_drink1=&drink1, ptr_drink2=&drink2, ptr_drink3=&drink3;
    int* ptr_orders=&order;
    char option;
    printf("Hello! I am a program made to handle your order. \n");
    printf("Here's our menu!\n");
    menu();
    while (orders>3||orders<1) {
        printf("How many meals would you like to order? ");
        scanf("%d", &orders);
        if (orders>3) {
        printf("\nSorry you can only order 3 or less meals!\n");
        }
        else if (orders<0) {
        printf("\nSorry you can't order a negative amount of meals!\n");
        }
    }
    while (orders!=0){
        if (orders==3) {
            order(ptr_orders, ptr_main1, ptr_side1, ptr_drink1);
        }
        else if (orders==2) {
            order(ptr_orders, ptr_main2, ptr_side2, ptr_drink2);
        }
        else if (orders==1) {
            order(ptr_orders, ptr_main3, ptr_side3, ptr_drink3);
        }
        else; 
        orders--;
    }
    total();
    printf("&d, %d, %d", main1, side1, drink1);
}