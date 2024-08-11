#include <stdio.h>
int main() {
    float number1, number2;
    printf("Enter two numbers: ");
    scanf("%f%f", &number1, &number2);
    switch(number1 > number2) {
        case 0:
            printf("%f is larger.", number2);
            break;
        case 1:
            printf("%f is larger.", number1);
            break;
    }
    return 0;
}
