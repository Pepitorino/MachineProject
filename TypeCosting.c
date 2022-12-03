#include <stdio.h>

void menu()
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

    sleep(2);

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

    sleep(2);

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

    sleep(2);
}

char* mainType(int main)
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

char* sideType(int side)
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

char* drinkType(int drink)
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

float mainCost(int main)
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

float sideCost(int side)
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

float drinkCost(int drink)
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
