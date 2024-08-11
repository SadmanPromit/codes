#include <stdio.h>
void main() {
    int num, sum = 0;
    printf("Enter any integer: ");
    scanf("%d", &num);
    printf("Sum of digits in %d: ", num);
    while(num != 0) {
        sum += num % 10;
        num /= 10;
    }
    printf("%d", sum);
}
