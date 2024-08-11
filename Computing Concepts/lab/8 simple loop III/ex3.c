#include <stdio.h>
int main() {
    int n;
    long long super_factorial = 1, factorial = 1;
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        factorial *= i;
        super_factorial *= factorial;
    }
    printf("Super-factorial of %d: %lld\n", n, super_factorial);
    return 0;
}
