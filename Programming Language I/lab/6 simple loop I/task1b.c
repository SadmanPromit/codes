//Program using for loop:
#include <stdio.h>
void main() {
    int n, i, sum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for(i = 3; i <= n; i += 4)
        sum += i;
    printf("Sum: %d", sum);
}
