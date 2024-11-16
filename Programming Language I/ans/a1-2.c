#include <stdio.h>
int main() {
    int number, first, last, sum;
    printf("Enter a four-digit number: ");
    scanf("%d", &number);
    last = number % 10;
    while(number >= 10)
        number /= 10;
    first = number;
    sum = first + last;
    printf("Sum: %d + %d = %d\n", first, last, sum);
    return 0;
}

