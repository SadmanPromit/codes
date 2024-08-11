#include <stdio.h>
#include <math.h>
float roundValue(float n, int d) {
    int multiplier = pow(10, d);
    return round(n * multiplier) / multiplier;  // Conventional way
}
int main() {
    float n;
    int d;
    printf("Enter n & d: ");
    scanf("%f %d", &n, &d);
    printf("Rounded value: %.*f\n", d, roundValue(n, d));   // Dynamically specify the precision
    return 0;
}
