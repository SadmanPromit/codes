#include <stdio.h>
#define PI 3.141592
void areaPeri(int *r);
int main() {
    int radius;
    printf("Enter radius(r): ");
    scanf("%d", &radius);
    areaPeri(&radius);
    return 0;
}
void areaPeri(int *r) {
    printf("Area = %f\nPerimeter = %f\n", PI * *r * *r, 2 * PI * *r);
}
