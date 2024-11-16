#include <stdio.h>
#define PI 3.141592
int main() {
    float edge, height, diameter, volume_cube, volume_cylinder;
    printf("Enter cube's edge, cylinder's height and diameter: ");
    scanf("%f%f%f", &edge, &height, &diameter);
    volume_cube = pow(edge, 3);
    volume_cylinder = PI * pow(diameter / 2, 2) * height;
    printf("Cube's volume: %f\nCylinder's volume: %f", volume_cube, volume_cylinder);
    return 0;
}
