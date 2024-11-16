#include <stdio.h>
int main() {
    int n, sum = 0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(int i = 1, term = 5, difference = 4; i <= n; i++) {
        sum += term * term;
        term += difference;
        difference += 2;
    }
    printf("Sum = %d\n", sum);
    return 0;
}
