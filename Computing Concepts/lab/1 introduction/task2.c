#include<stdio.h>
int main() {
    float first, second, third, average;
    printf("Insert first number: ");
    scanf("%f", &first);
    printf("Insert second number: ");
    scanf("%f", &second);
    printf("Insert third number: ");
    scanf("%f", &third);
    average = (first + second + third) / 3;
    printf("\nThe average is: %.1f\n", average);
}
