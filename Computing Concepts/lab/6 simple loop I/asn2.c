#include <stdio.h>
int main() {
    int sum = 0;
    for(int i = 10000; i >= 8; i /= 5)
        sum += i;
    printf("Sum: %d", sum);
    return 0;
}
