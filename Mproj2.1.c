#include <stdio.h>
#include "functions.c"

int main (){
    int orders, ordernum=1, i;
    int main[4];
    int side[4];
    int drink[4];
    char ans;
    float total;

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

    while (ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N'){
        printf("\nProceed with order(Y/N)? ");
        scanf(" %c", &ans);
        if (ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N') printf("Invalid option");
        if (ans=='N') orders=0;
    }

    for(i=orders; i>0; i--){
            order(&main[i], &side[i], &drink[i], ordernum);
            ordernum++;

        if (ans=='y'||ans=='Y') ans='\0';
    
        while (ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N'){
            printf("\nProceed with rest of order(Y/N)? ");
            scanf(" %c", &ans);
            if (ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N') printf("Invalid option\n");
            if (ans=='N') {
                i=0;
            }
     }
    }

    if (ans=='y'||ans=='Y') ans='\0';

    while (ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N'){
        printf("\nProceed with order(Y/N)? ");
        scanf(" %c", &ans);
        if (ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N') printf("Invalid option\n");
        if (ans=='N') orders=0;
    }

    ordernum=1;

    for(i=orders; i!=0; i--){
        displaysubtotal(main[i], side[i], drink[i], ordernum);
        ordernum++;
        total+=subtotal(main[i], side[i], drink[i]);
    }
    printf ("\nTotal amount due: %.2f\n", total);

}
