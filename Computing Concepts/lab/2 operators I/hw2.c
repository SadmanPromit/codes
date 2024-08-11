#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c, solution1, solution2;
    printf("Enter a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);
    solution1 = (- b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    solution2 = (- b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    printf("Solution 1: %f\nSolution 2: %f", solution1, solution2);
    return 0;
}
