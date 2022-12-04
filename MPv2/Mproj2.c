#include <stdio.h>

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
    printf("\n|4 |\tFruit Juice    \t|55.000\t\t| ");
    printf("\n-----------------------------------------\n");
}

char* mainnum(int main){
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
        return "Invalid order, main set to none";
    }
}

char* sidenum(int side){
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
        return "Invalid order, side set to none";
    }
}

char* drinknum(int drink){
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
        return "Invalid order, drink set to none";
    }
}

void order(int *main, int *side, int *drink, int ordernum){
    char correct;
    do {
        printf("\nOrder %d:", ordernum);

        printf("\n\tMain: ");
        scanf("%d", main);
        printf("\t\t%s\n", mainnum(*main));
        if (*main>4||*main<0) *main=0;

        printf("\n\tSide: ");
        scanf("%d", side);
        printf("\t\t%s\n", sidenum(*side));
        if (*side>4||*side<0) *side=0;

        printf("\n\tDrink: ");
        scanf("%d", drink);
        printf("\t\t%s\n", drinknum(*drink));
        if (*drink>4||*drink<0) *drink=0;

        printf("Is this order correct(Y/N)? ");
        scanf(" %c", &correct);
    } while (correct!='Y');
}

void total(){

}

int main (){
    int orders, ordernum=1;
    int main1, main2, main3;
    int side1, side2, side3;
    int drink1, drink2, drink3;
    char answer;

    printf("Hello! I am a program made to take your order.\n");

    do {
        printf("\nHow many meals would you like to order? (maximum 3)? ");
        scanf("%i", &orders);
        if (orders>3){
            printf("I'm sorry, you can only order 1 to 3 meals\n");
        }
        else if (orders<0){
            printf("I'm sorry you can't order a negative amount of meals.\n");
        }
    } while (orders>3||orders<0);

    while (orders!=0){
        if (orders==3){
            order(&main3, &side3, &drink3, ordernum);
            ordernum++;
        }
        else if (orders==2){
            order(&main2, &side2, &drink2, ordernum);
            ordernum++;
        }
        else if (orders==1){
            order(&main1, &side1, &drink1, ordernum);
            ordernum++;
        }
        orders--;
    }
}