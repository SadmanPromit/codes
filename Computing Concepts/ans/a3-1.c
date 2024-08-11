#include <stdio.h>
double getArea (int a, int b, int h);
int main() {
    int a, b, h;
    printf("Enter two parallel sides (a and b) and the height of the trapezoid (h): ");
    scanf("%d %d %d", &a, &b, &h);
    printf("Area = %lf\n", getArea(a, b, h));
    return 0;
}
double getArea (int a, int b, int h) {
    return (double) 1 / 2 * (a + b) * h;
}
