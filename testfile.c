#include <stdio.h>

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
            printf("Invalid order, main set to none");
    }
}

 int main (){
    printf("%s", mainnum(2));
 }
