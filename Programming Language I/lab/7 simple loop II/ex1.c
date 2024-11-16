#include <stdio.h>
int main() {
    int number, first, last;
    printf("Enter number: ");
    scanf("%d", &number);
    last = number % 10;
    for(int i = 1; i <= number; i++)
        number /= 10;
    first = number % 10;
    printf("First digit: %d\nLast digit: %d", first, last);
    return 0;
}
