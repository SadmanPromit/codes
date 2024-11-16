#include <stdio.h>
#include <math.h>
#define PI 3.141592
void main() {
    float radius, volume;
    printf("Enter radius: ");
    scanf("%f", &radius);
    volume = 4 * PI * pow(radius, 3) / 3;
    printf("\nVolume: %f\n", volume);
}
