#include <stdio.h>
int main() {
    int decimal, binary = 0, multiplier = 1;
    printf("Enter decimal number: ");
    scanf("%d", &decimal);
    while(decimal != 0) {
        binary += decimal % 2 * multiplier;
        decimal /= 2;
        multiplier *= 10;
    }
    printf("Binary equivalent: %d\n", binary);
    return 0;
}
