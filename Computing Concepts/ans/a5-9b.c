#include <stdio.h>
int fibonacci(int, int *);
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int memo[n + 1];    // Dynamic memory
    for(int index = 0; index <= n; ++index)
        memo[index] = -1;   // Initialize
    printf("The nth Fibonacci number = %d\n", fibonacci(n, memo));
    return 0;
}
int fibonacci(int n, int *memo) {
    if(memo[n] != -1)   // Check if already computed
        return memo[n];
    int current;
    if(n <= 1)
        return memo[n] = n;   // fibonacci(0) = 0 & fibonacci(1) = 1
    else
        return memo[n] = fibonacci(n - 2, memo) + fibonacci(n - 1, memo);
}
