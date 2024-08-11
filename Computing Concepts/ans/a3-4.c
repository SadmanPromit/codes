#include <stdio.h>
int sumOfDigits(int x);
int main() {
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Sum = %d\n", sumOfDigits(x));
    return 0;
}
int sumOfDigits(int x) {
    int sum = 0;
    while(x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
