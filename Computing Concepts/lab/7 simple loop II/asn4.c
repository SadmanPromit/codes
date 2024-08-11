#include <stdio.h>
int main() {
    int integer, sum = 0, isPrime = 1;
    printf("Enter any integer: ");
    scanf("%d", &integer);
    while(integer != 0) {
        sum += integer % 10;
        integer /= 10;
    }
    printf("Sum of its digits = %d. ", sum);
    for(int i = 2; i <= sum / 2; i++)
        if(sum % i == 0) {
            isPrime = 0;
            break;
        }
    if(isPrime == 1)
        printf("It is a prime number.");
    else
        printf("It is not a prime number.");
    return 0;
}
