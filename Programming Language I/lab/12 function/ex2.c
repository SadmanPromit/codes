#include <stdio.h>
int sumSeries(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += i * i;
    return sum;
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Sum = %d\n", sumSeries(n));
    return 0;
}
