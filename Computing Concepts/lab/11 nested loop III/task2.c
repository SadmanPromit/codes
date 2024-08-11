#include<stdio.h>
#include<conio.h>
int main() {
    int N, i, j, isPrime;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    // For each number between 2 to N, check if it is prime number or not
    printf("Prime no. from %d to %d: ", 1, N);
    for(i = 2; i <= N; i++) {
        isPrime = 1;
        // Check if i is prime
        for(j = 2; j <= i / 2; j++)
             if(i % j == 0){
                 isPrime = 0;
                 break;
             }
        if(isPrime == 1)
            printf("%d ", i);
    }
}
