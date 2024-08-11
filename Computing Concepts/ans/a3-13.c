#include <stdio.h>
int main() {
    int n;
    double sum = 0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        sum += (double) (i * i * i + i) / i / i / i / i;
    printf("Sum = %lf\n", sum);
    return 0;
}
