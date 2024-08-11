#include<stdio.h>
int main() {
    int number;
    float decimal;
    char name[20];
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("Enter a decimal number: ");
    scanf("%f", &decimal);
    printf("Enter your name: ");
    scanf("%s",&name);
    printf("\nThe integer is %d\nThe decimal number is %.2f\nYour name is: %s", number, decimal, name);
}
