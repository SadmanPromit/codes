#include <stdio.h>
void main() {
    int num;
    printf("Enter any number to check even or odd: ");
    scanf("%d", &num);
    switch(num % 2) {
        //If n % 2 == 0
        case 0:
            printf("Number is Even");
            break;
        //Else if n % 2 != 0
        case 1:
            printf("Number is Odd");
            break;
    }
}
