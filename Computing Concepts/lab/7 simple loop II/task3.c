#include <stdio.h>
void main() {
    int num, count = 0;
    printf("Enter any integer: ");
    scanf("%d", &num);
    while(num != 0) {
        // Current digit is num % 10
        if(num % 10 != 0)
            count++;
        num /= 10;
    }
    printf("Total nonzero digits: %d", count);
}
