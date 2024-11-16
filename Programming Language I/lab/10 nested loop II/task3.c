#include<stdio.h>
void main() {
    int i, j, n;
    float sum = 0, term;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        // Compute i-th term = 1 / 1 + 1 / 2 + ... + 1 / i
        term = 0;
        for(j = 1; j <= i ; j++)
            term += 1.0 / j;
        // Add i-th term with sum
        sum += term;
    }   // i
    printf("%f\n", sum);
}   // main
