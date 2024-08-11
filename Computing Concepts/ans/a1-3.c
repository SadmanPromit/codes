#include <stdio.h>
int main() {
    float celsius, fahrenheit;
    printf("Enter Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = celsius * ((float) 9 / 5) + 32;
    printf("Fahrenheit: %f\n", fahrenheit);
    return 0;
}

