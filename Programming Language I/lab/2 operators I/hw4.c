#include <stdio.h>
int main() {
    int x, y, quotient , remainder ;
    printf("Enter x, y: ");
    scanf("%d%d", &x, &y);
    quotient = x / y;
    remainder = x % y;
    printf("x / y\nQuotient: %d\nRemainder: %d\n", quotient, remainder);
    quotient = y / x;
    remainder = y % x;
    printf("y / x\nQuotient: %d\nRemainder: %d", quotient, remainder);
    return 0;
}
