#include <stdio.h>
#define PI 3.14
int main() {
    float radius, sa;
    printf("Please enter the radius of a sphere: ");
    scanf("%f", &radius);
    sa =  4 * PI * radius * radius;
    printf("The surface area of a sphere: %.2f", sa);
}
