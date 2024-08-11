#include<stdio.h>
int main() {
    float const PI = 3.142;
    float radius, area, circumference, diameter;
    printf("Enter the radius of a circle: ");
    scanf("%f", &radius);
    diameter = 2 * radius;
    circumference = 2 * PI * radius;
    area = PI * radius * radius;
    printf("\nThe Diameter is: %.2f \nThe Circumference is: %.2f \nThe area is: %.2f \n", diameter, circumference, area);
}
