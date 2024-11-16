#include <stdio.h>
#include <math.h>
#define PI 3.141592
int main() {
    float radius, height, volume, surface_area;
    printf("Enter radius: ");
    scanf("%f", &radius);
    printf("Enter height: ");
    scanf("%f", &height);
    volume =  PI * pow(radius, 2) * height / 3;
    surface_area = PI * radius * (radius + sqrt(pow(height, 2) + pow(radius, 2)));
    printf("Volume: %f\nSurface area: %f", volume, surface_area);
}

