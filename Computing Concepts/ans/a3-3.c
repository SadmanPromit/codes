#include <stdio.h>
double harmonicSum(int n);
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Sum = %lf\n", harmonicSum(n));
    return 0;
}
double harmonicSum(int n) {
    double sum = 0;
    for(int i = 1; i <= n; i++)
        sum += (double) 1 / i;
    return sum;
}
