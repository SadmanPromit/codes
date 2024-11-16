#include<stdio.h>
int main() {
    int first, second, sum, product, difference, quotient, remainder;
    printf("Insert first number: ");
    scanf("%d", &first);
    printf("Insert second number: ");
    scanf("%d", &second);
    sum = first + second;
    product = first * second;
    difference = first - second;
    quotient = first / second;
    remainder = first - second * quotient;
    printf("\nSum: %d \nProduct: %d \nDifference: %d \nQuotient: %d \nRemainder: %d\n", sum, product, difference, quotient, remainder);
}
