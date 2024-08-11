#include <stdio.h>
int main() {
    int base, power, output = 1;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter power: ");
    scanf("%d", &power);
    for(int i = 1; i <= power; i++)
        output *= base;
    printf("%d to the power %d = %d\n", base, power, output);
    return 0;
}
