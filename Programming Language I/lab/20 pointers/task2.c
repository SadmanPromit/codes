#include <stdio.h>
void sum(float *, float *);
int main() {
    float number1, number2;
    printf("Enter two numbers: ");
    scanf("%f %f", &number1, &number2);
    sum(&number1, &number2);
    return 0;
}
void sum(float *number1, float *number2) {
    printf("Sum = %f\n", *number1 + *number2);
}
