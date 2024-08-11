#include <stdio.h>
int main() {
    int n, sum = 0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(int i = 1, term = 0; i <= n; i++)
        sum += term = term * 10 + 2;
    printf("Sum = %d\n", sum);
    return 0;
}
