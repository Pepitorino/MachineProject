#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Order 
{
    int main;
    int side;
    int drink;
};

void flush(){
    char flush;
    do {
        flush=getchar();
    } while (flush!=EOF&&flush!='\n');
}

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

void displayMealset (struct Order order);
float subtotal (struct Order order, struct Order orderDay);
void order (struct Order* orders, struct Order orderDay, int* ordernum);
// void total (struct Order orders, struct Order orderDay, int* ordernum)

void displayMealset (struct Order order)
{
    printf("\nMain: %d", order.main);
    printf("\n\t%s", mainType(order.main));
    printf("\t%.2f", mainCost(order.main));
    printf("\nSide: %d", order.side);
    printf("\n\t%s", sideType(order.side));
    printf("\t%.2f", sideCost(order.side));
    printf("\nDrink: %d", order.drink);
    printf("\n\t%s", drinkType(order.drink));
    printf("\t%.2f", drinkCost(order.drink));
    
    return;
}

float subtotal (struct Order order, struct Order orderDay)
{
    float subtotal = mainCost(order.main)+sideCost(order.side)+drinkCost(order.drink);
    if (compare(order, orderDay))
        return subtotal-subtotal*0.15;
    return subtotal;
}

void order (struct Order* orders, struct Order orderDay, int* ordernum)
{
    int i;
    char ans;
    do {
        printf("\n\nHow many orders would you like? (Maximum of 3)\t");
        scanf("%d", ordernum);
        fflush(stdin);

        if (*ordernum<0||*ordernum>3) printf("Invalid amount");

    } while (*ordernum<0||*ordernum>3);

    for (i=1; i<=*ordernum; i++){
        printf("\nOrder %d:", i);

        do {
            printf("\nChoose an option:");
            printf("\n\n\t1. Choose Mealset");
            printf("\n\t2. Mealset of the Day");
            printf("\n\t3. Randomize Mealset\nOption: ");
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
                printf("\t%.2f", mainCost(orders[i].main));

                printf("\n\tSide:\t");
                scanf(" %d", &orders[i].side);
                fflush(stdin);
                printf("\t\t%s", sideType(orders[i].side));
                if (orders[i].side>4||orders[i].side<0) orders[i].side=0;
                printf("\t%.2f", sideCost(orders[i].side));

                printf("\n\tDrink:\t");
                scanf(" %d", &orders[i].drink);
                fflush(stdin);
                printf("\t\t%s", drinkType(orders[i].drink));
                if (orders[i].drink>4||orders[i].drink<0) orders[i].drink=0;
                printf("\t%.2f", drinkCost(orders[i].drink));
                break;
        }

        if (compare(orders[i], orderDay)){
            printf("\n\n\tMealset of the Day Bonus: -15%%");
        }

        printf("\n\nSubtotal: %.2f", subtotal(orders[i], orderDay));

        do {
            printf("\n\nIs this order correct? (Y/N)");
            printf("\nOption: ");
            scanf(" %c", &ans);

            if (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n') printf("\nInvalid Option.");
        } while (ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n');

        if (ans=='n'||ans=='N'){
            i--;
        }

    }
    
}

/*void total(struct Order orders, struct Order orderDay, int* ordernum)
{

}*/

