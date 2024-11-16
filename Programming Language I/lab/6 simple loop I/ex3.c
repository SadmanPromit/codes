#include <stdio.h>
int main() {
    int n, i = 4, sum = 0;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    while(i <= n) {
        sum += i;
        i += 7;
    }
    printf("Sum: %d\n", sum);
    return 0;
}
