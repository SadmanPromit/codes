#include <stdio.h>
int main() {
    float a, b;
    printf("Enter a number: ");
    scanf("%f", &a);
    b = a;
    a = a + 1;
    printf("%f, %f", a, b);
    return 0;
}
