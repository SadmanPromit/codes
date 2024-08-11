#include <stdio.h>
#include <math.h>
int checkPrimeNumber(int n);
int main() {
    int number1, number2;
    printf("Enter two numbers: ");
    scanf("%d %d", &number1, &number2);
    printf("All the prime numbers between %d and %d are: ", number1, number2);
    for(int i = number1, first_flag = 0; i <= number2; i++) {
        if(checkPrimeNumber(i) && first_flag)
            printf(", %d", i);
        else if(checkPrimeNumber(i) && !first_flag) {
            printf("%d", i);
            first_flag++;
        }
    }
    printf(".\n");
    return 0;
}
int checkPrimeNumber(int n) {
    // Excluding numbers below 2
    if(n <= 1)
        return 0;
    // False condition with optimization
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return 0;
    // True condition
    return 1;
}
