#include <stdio.h>
int main() {
    int binary, decimal = 0, multiplier = 1;
    printf("Enter binary number: ");
    scanf("%d", &binary);
    while(binary != 0) {
        decimal += binary % 10 * multiplier;
        binary /= 10;
        multiplier *= 2;
    }
    printf("Decimal equivalent: %d\n", decimal);
    return 0;
}
