#include <stdio.h>
#include <math.h>
int checkPrimeNumber(int n);
int main() {
    int integer, sum = 0;
    do {
        printf("Enter an integer: ");
        scanf("%d", &integer);
        if(integer <= 1)
            continue;
        if(checkPrimeNumber(integer)) {
            sum += integer;
            printf("%d is Prime, add to sum\n", integer);
        }
        else
            printf("%d Not prime\n", integer);
    } while(integer >= 0);
    printf("The sum=%d\n", sum);
    return 0;
}
int checkPrimeNumber(int n) {
    if(n == 2)
        return 1;   // Skipping 2 for checking even numbers below
    if(n % 2 == 0)
        return 0;   // Skipping even numbers for optimality
    for(int i = 3; i <= sqrt(n); i += 2)   // False condition with optimization
        if(n % i == 0)
            return 0;
    return 1;   // True condition
}
