#include <stdio.h>
int main() {
    int sum = 0;
    for(int i = 1; i <= 126; i += 2)    // Only looping through odd numbers
        sum += i * i;
    printf("The sum of squares of all odd numbers between 1 and 126: %d\n", sum);
    return 0;
}
