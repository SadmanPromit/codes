#include <stdio.h>
double seriesSum(int number) {
    int factorial = 1;
    double sum = 0;
    for(int i = 1; i <= number; i++) {
        factorial *= i;
        sum += (double) i / factorial;
    }
    return sum;
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Sum of the series = %lf\n", seriesSum(n));
    return 0;
}
