#include <stdio.h>
int main() {
    int number, reverse = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Reverse of %d is: ", number);
    while(number != 0) {
        reverse = reverse * 10 + (number % 10);
        number /= 10;
    }
    printf("%d", reverse);
    return 0;
}
