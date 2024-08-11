#include <stdio.h>
float getBase();
float getHeight();
float getAreaTriangle(float base, float height);
int main() {
    float base = getBase(), height = getHeight();
    printf("The base is: %.1f cm and height is: %.1f cm\nThe area of the triangle is : %.1f\n", base, height, getAreaTriangle(base, height));
    return 0;
}
float getBase() {
    float base;
    printf("Enter base: ");
    scanf("%f", &base);
    return base;
}
float getHeight() {
    float height;
    printf("Enter height: ");
    scanf("%f", &height);
    return height;
}
float getAreaTriangle(float base, float height) {
    return (float) 1 / 2 * base * height;
}
