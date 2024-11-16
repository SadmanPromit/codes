#include <stdio.h>
int main() {
    int n;
    long long quadruple_factorial = 1;
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i = n + 1; i <= 2 * n; i++)
        quadruple_factorial *= i;
    printf("Quadruple factorial of %d: %lld\n", n, quadruple_factorial);
    return 0;
}
