#include <stdio.h>
int main() {
    float celsius, fahrenheit;
    printf("Enter Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = celsius * 9 / 5 + 32;
    printf("Fahrenheit: %f", fahrenheit);
    return 0;
}
