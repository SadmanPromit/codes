#include <stdio.h>
void main() {
    int i, j, n, sum = 0;
    printf("Enter any number to print perfect number up to: ");
    scanf("%d", &n);
    printf("All Perfect numbers between 1 to %d: ", n);
    // Iterates from 1 to n and print if it is perfect number
    for(i = 1; i <= n; i++) {
        sum = 0;
        // Print i if the current value of i is a Perfect number
        for(j = 1; j < i; j++)
            if(i % j == 0) // if j is a divisor of i then add j with sum
                sum += j;
        // Now sum = (sum of all proper divisors of i)
        if(sum == i) // If the current value of i is Perfect
            printf("%d, ", i);
    }
} // main
