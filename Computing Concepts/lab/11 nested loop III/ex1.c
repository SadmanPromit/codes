#include <stdio.h>
int main() {
    int n, i, j, isPrime;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("All prime numbers between 1 and 20 (in reverse order): ");
    for(i = n; i >= 2; i--) {
        isPrime = 1;
        for(j = 2; j <= i / 2; j++)
             if(i % j == 0){
                 isPrime = 0;
                 break;
             }
        if(isPrime == 1)
            printf("%d ", i);
    }
    return 0;
}
