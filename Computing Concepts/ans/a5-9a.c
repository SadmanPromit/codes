#include <stdio.h>
int fibonacci(int n);
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("The nth Fibonacci number = %d\n", fibonacci(n));
    return 0;
}
int fibonacci(int n) {
    int current;
    if(n <= 1)
        return n;   // fibonacci(0) = 0 & fibonacci(1) = 1
    for(int i = 2, previous_previous = 0, previous = 1; i <= n; ++i) {
        current = previous_previous + previous;
        previous_previous = previous;
        previous = current;
    }
    return current;
}
