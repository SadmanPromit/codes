#include <stdio.h>
int main() {
    float base_a, base_b, height, area_trapezoid, area_parallelogram;
    printf("Enter base a: ");
    scanf("%f", &base_a);
    printf("Enter base b: ");
    scanf("%f", &base_b);
    printf("Enter height: ");
    scanf("%f", &height);
    area_trapezoid =  (base_a + base_b) * height / 2;
    area_parallelogram = base_b * height;
    printf("Trapezoid area: %f\nParallelogram area: %f", area_trapezoid, area_parallelogram);
}

