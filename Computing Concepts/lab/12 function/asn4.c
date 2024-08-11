#include <stdio.h>
int reverse(int number) {
    int reverse_number = 0;
    while(number != 0) {
        reverse_number = reverse_number * 10 + number % 10;
        number /= 10;
    }
    return reverse_number;
}
int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("Reverse: %d\n", reverse(number));
    return 0;
}
