#include <stdio.h>
int main() {
    int minimum, maximum, difference, sum;
    printf("Enter minimum: ");
    scanf("%d", &minimum);
    printf("Enter maximum: ");
    scanf("%d", &maximum);
    printf("Enter Common difference: ");
    scanf("%d", &difference);
    printf("The Sum is: %d ", minimum);
    sum = minimum;
    for(int i = minimum + difference; i <= maximum; i += difference) {
        sum += i;
        printf("+ %d ", i);
    }
    printf("= %d\n", sum);
    return 0;
}
