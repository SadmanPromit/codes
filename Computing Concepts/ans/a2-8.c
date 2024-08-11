#include <stdio.h>
int main() {
    int num, sum = 0, prime_flag = 1;
    printf("Enter any integer: ");
    scanf("%d", &num);
    while(num != 0) {
        sum += num % 10;
        num /= 10;
    }
    printf("Sum of its digits = %d.\n", sum);
    // False condition
    for(int i = 2; i <= sum / 2; i++)
        if(sum % i == 0) {
            prime_flag = 0;
            break;
        }
    // Excluding numbers below 2
    if(!prime_flag || sum <= 1)
        printf("%d is not a prime number.\n", sum);
    // True condition
    else
        printf("%d is a prime number.\n", sum);
    return 0;
}
