#include <stdio.h>
void main() {
    int num, count = 0;
    printf("Enter any integer: ");
    scanf("%d", &num);
    while(num != 0) {
        count++;
        num /= 10;
    }
    printf("Total digits: %d", count);
}
