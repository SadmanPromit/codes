#include <stdio.h>
int main() {
    int number, number_temp, reverse = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    number_temp = number;
    while(number != 0) {
        reverse = reverse * 10 + (number % 10);
        number /= 10;
    }
    if(reverse == number_temp)
        printf("Palindrome.");
    else
        printf("Not palindrome.");
    return 0;
}
