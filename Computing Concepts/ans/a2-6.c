#include <stdio.h>
int main() {
    int n;
    double sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int factorial = 1;
        for(int j = 1; j <= i; j++)
            factorial *= j;
        sum += 1 / (double) factorial;
    }
    printf("Sum: %lf\n", sum);
    return 0;
}
