#include <stdio.h>
#define PI 3.141592
float diameter(float radius) {
    return 2 * radius;
}
float circumference(float radius) {
    return 2 * PI * radius;
}
float area(float radius) {
    return PI * radius * radius;
}
int main() {
    float radius;
    printf("Enter circle's radius: ");
    scanf("%f", &radius);
    printf("Diameter = %f\nCircumference = %f\nArea = %f\n", diameter(radius), circumference(radius), area(radius));
    return 0;
}
