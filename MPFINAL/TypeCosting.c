#include <stdio.h>
#include <stdlib.h>

/*Prints menu for user.
Precondition: No precondition
@return void
*/
void 
menu()
{
    printf("Menu:");
    printf("\n\nMains:");
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
    printf("\n|4 |\tFruit Juice    \t|55.000\t\t| ");
    printf("\n-----------------------------------------\n");

}

/*This function returns type of main given the id.
Precondition: No precondition.
@param main is the id of the main.
@return type of main as a string literal.
*/
char* 
mainType(int main)
{
    switch (main) {
        case 0:
        return "None";

        case 1:
        return "Chicken";

        case 2:
        return "Pork";

        case 3:
        return "Fish";

        case 4:
        return "Beef";

        default:
        return "Invalid, main set to none";
    }
}

/*This function returns type of side given the id.
Precondition: No precondition.
@param side is the id of the side
@return type of side as a string literal
*/
char* 
sideType(int side)
{
    switch (side) {
        case 0:
        return "None";

        case 1:
        return "Steamed Rice";

        case 2:
        return "Shredded Corn";

        case 3:
        return "Mashed Potato";

        case 4:
        return "Steam Vegetables";
        
        default:
        return "Invalid, side set to none";
    }
}

/*This function returns type of drink given the id.
Precondition: No precondition.
@param drink is the id of the drink
@return type of drink as a string literal
*/
char* 
drinkType(int drink)
{
    switch (drink) {
        case 0:
        return "None";
        
        case 1:
        return "Mineral Water";
        
        case 2:
        return "Iced Tea";
        
        case 3:
        return "Soda";
        
        case 4:
        return "Fruit Juice";

        default:
        return "Invalid, drink set to none";
    }
}


/*This function returns the cost of main given the id.
Precondition: No precondition
@param main is the id of the main
@return cost of main
*/
float 
mainCost(int main)
{
    switch (main){
        case 1:
        return 90;

        case 2:
        return 105;

        case 3:
        return 120;

        case 4:
        return 135;

        default:
        return 0;
    }
}

/*This function returns the cost of side given the id.
Precondition: No precondition
@param side is the id of the side
@return cost of side
*/
float 
sideCost(int side)
{
    switch (side){        
        case 1:
        return 20;

        case 2:
        return 35;

        case 3:
        return 50;

        case 4:
        return 65;

        default:
        return 0;
    }
}

/*This function returns the cost of drink given the id.
Precondition: No precondition
@param drink is the id of the drink
@return cost of drink
*/
float 
drinkCost(int drink)
{
    switch (drink){
        case 1:
        return 25;

        case 2:
        return 35; 

        case 3:
        return 45;

        case 4:
        return 55;

        default:
        return 0;
    }
}
