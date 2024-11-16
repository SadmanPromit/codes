#include <stdio.h>
#include <math.h>
int main() {
    float a;
    printf("Enter a number: ");
    scanf("%f", &a);
    printf("%f, %f", sqrt(a), pow(a, 3));
}
