#include<stdio.h>
void main() {
    int n, i = 2, count = 0, j, isPrime;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("First %d prime numbers: ", n);
    while (count < n) {
        // If current value of i is a prime no., then print it
        isPrime = 1;  // Let the current value of i is a prime no.
        for (j = 2 ; j <= i / 2; j++)
            // If i has a divisor then i is not prime
            if (i % j == 0){
                isPrime = 0; // So assign 0 to isPrime to indicate this
                break;
            }
        // for
        if (isPrime) {
            printf("%d, ", i); // Move this outside for loop to print n-th prime
            count++;
        }
        i++;
    } // while
} // main
