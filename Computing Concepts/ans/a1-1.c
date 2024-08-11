#include <stdio.h>
int main() {
    int x, y, quotient , remainder ;
    printf("Enter x, y: ");
    scanf("%d%d", &x, &y);
    quotient = x / y;
    remainder = x % y;
    printf("%d / %d\nQuotient: %d\nRemainder: %d\n", x, y, quotient, remainder);
    quotient = y / x;
    remainder = y % x;
    printf("%d / %d\nQuotient: %d\nRemainder: %d\n", y, x, quotient, remainder);
    return 0;
}

