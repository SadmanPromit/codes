#include <stdio.h>
#include <math.h>
int main() {
    float base, height, hypotenuse;
    printf("Enter base: ");
    scanf("%f", &base);
    printf("Enter height: ");
    scanf("%f", &height);
    hypotenuse = sqrt(pow(base, 2) + pow(height, 2));
    printf("Hypotenuse: %f", hypotenuse);
}

