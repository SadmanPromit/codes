#include <stdio.h>
int main() {
    int m, n, i, j, isPrime, sum = 0;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = m; i <= n; i++) {
        isPrime = 1;
        for(j = 2; j <= i / 2; j++)
             if(i % j == 0){
                 isPrime = 0;
                 break;
             }
        if(isPrime == 1)
            sum += i;
    }
    printf("Sum of all prime numbers between %d and %d: %d", m, n, sum);
    return 0;
}
