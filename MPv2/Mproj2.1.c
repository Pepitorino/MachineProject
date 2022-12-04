#include <stdio.h>
#include "functions.c"
#include <time.h>
#include <stdlib.h>

int main (){

    srand(time(NULL));
    int mainday=(rand()%4+1), sideday=(rand()%4+1), drinkday=(rand()%4+1);
    int orders, ordernum=1, i;
    int main[4]={0};
    int side[4]={0};
    int drink[4]={0};
    char ans;
    float total;

    printf("Hello! I am a program made to take your order.\n");
    sleep(1);
    menu();
    sleep(1);
    printf("\nThe Meal of the Day is: %d %d %d", mainday, sideday, drinkday);

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

    orders=proceed(&ans, orders);

    for(i=orders; i>0; i--){
            order(&main[i], &side[i], &drink[i], ordernum);
            ordernum++;

        if (ans=='y'||ans=='Y') ans='\0';
    
        if (i>1){
        	while (ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N'){
            	printf("\nProceed with rest of order(Y/N)? ");
            	scanf(" %c", &ans);
            	if (ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N') printf("Invalid option\n");
            	if (ans=='N'||ans=='n') {
                i=0;
            }	
		}
     }
    }

    if (ans=='y'||ans=='Y') ans='\0';

    orders=proceed(&ans, orders);

    ordernum=1;

    for(i=orders; i!=0; i--){
        displaysubtotal(main[i], side[i], drink[i], ordernum, mainday, sideday, drinkday);
        ordernum++;
        total+=subtotal(main[i], side[i], drink[i], mainday, sideday, drinkday);
    }
    printf ("\nTotal amount due: %.2f\n", total);
    return 0;
}
