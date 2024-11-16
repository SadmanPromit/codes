#include <stdio.h>
#include <math.h>   // Using for optimality
int special(int num);
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if(special(number))
        printf("%d is special.\n", number);
    else
        printf("%d is not special.\n", number);
    return 0;
}
int special(int num) {
    int divisor_sum = 1;  // Common divisor 1
    for(int i = 2; i <= sqrt(num); i++) // Optimization
        if(num % i == 0) {
            divisor_sum += i;
            int quotient = num / i; // Temporary variable of optimality
            if(i != quotient)
                divisor_sum += quotient;    // The other unique divisor larger than sqrt(num)
        }
    if(divisor_sum > num)
        return 1;
    return 0;
}
