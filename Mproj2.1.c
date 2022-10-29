#include <stdio.h>
#include <functions.c>

int main (){
    int orders, ordernum=1, i;
    int main[3];
    int side[3];
    int drink[3];
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

    for(orders; orders!=0; orders--){
            order(&main[orders], &side[orders], &drink[orders], ordernum);
            ordernum++;
    }


}