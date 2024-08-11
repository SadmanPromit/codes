#include <stdio.h>
int main() {
    int minimum, maximum, ratio, sum;
    printf("Enter minimum: ");
    scanf("%d", &minimum);
    printf("Enter maximum: ");
    scanf("%d", &maximum);
    printf("Enter Common ratio: ");
    scanf("%d", &ratio);
    printf("The Sum is: %d ", minimum);
    sum = minimum;
    for(int i = minimum * ratio; i <= maximum; i *= ratio) {
        sum += i;
        printf("+ %d ", i);
    }
    printf("= %d\n", sum);
    return 0;
}
