#include <stdio.h>
int main() {
    float celsius, fahrenheit;
    printf("Enter Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("Celsius: %f\n", celsius);
    return 0;
}
