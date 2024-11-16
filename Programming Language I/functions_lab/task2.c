#include <stdio.h>
int Factorial(int);
int Combination(int, int);
int main() {
    int n, r;
    printf("Enter values of n and r: ");
    scanf("%d %d", &n, &r);
    printf("Combination: %d\n", Combination(n, r));
    return 0;
}
int Factorial(int x) {
    int factorial = 1;
    for(int i = 2; i <= x; i++)
        factorial *= i;
    return factorial;
}
int Combination(int n, int r) {
    return Factorial(n) / Factorial(r) / Factorial(n - r);
}
