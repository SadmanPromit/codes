#include <stdio.h>
int main() {
    int integer, reverse = 0, isPrime = 1;
    printf("Enter any integer: ");
    scanf("%d", &integer);
    while(integer != 0) {
        reverse = reverse * 10 + (integer % 10);
        integer /= 10;
    }
    printf("Reverse number is: %d.  ", reverse);
    for(int i = 2; i <= reverse / 2; i++)
        if(reverse % i == 0) {
            isPrime = 0;
            break;
        }
    if(isPrime == 1)
        printf("It is a prime number.");
    else
        printf("It is not a prime number.");
    return 0;
}
