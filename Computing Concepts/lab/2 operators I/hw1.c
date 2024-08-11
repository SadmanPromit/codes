#include <stdio.h>
#include <math.h>
int main() {
    float x, output;
    printf("Enter x: ");
    scanf("%f", &x);
    output = 5 * pow(x, 3) - 4 * pow(x, 2) + sqrt(x) + 3;
    printf("Output: %f", output);
    return 0;
}
