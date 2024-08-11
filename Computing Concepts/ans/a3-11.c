#include <stdio.h>
int main() {
    int n;
    double sum = 0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        if(i % 2 == 0)
            sum -= (double) i / (i + 1);
        else
            sum += (double) i / (i + 1);
    printf("Sum = %lf\n", sum);
    return 0;
}
