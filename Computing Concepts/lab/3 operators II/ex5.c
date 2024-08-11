#include <stdio.h>
#define PI 3.14
int main() {
    float arc, radius, angle;
    printf("Enter the arc length and radius: ");
    scanf("%f%f", &arc, &radius);
    angle =  arc / radius;
    printf("Angle of the segment: %.2f", angle);
}

