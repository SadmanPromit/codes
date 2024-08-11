#include <stdio.h>
int fibo(int n);
int main() {
    int n;
    printf("Enter term number: ");
    scanf("%d", &n);
    printf("Sum of fibonacci numbers unto %d terms = %d\n", n, fibo(n));
    return 0;
}
int fibo(int n) {
    if(n <= 1)
        return n;   // For the first two terms
    int sum = 1;    // For the first two terms
    for(int i = 2, previous_previous = 0, previous = 1, current; i <= n; i++) { // For the rest of the terms
        sum += current = previous_previous + previous;
        previous_previous = previous;   // Update
        previous = current; // Update
    }
    return sum;
}
