#include <stdio.h>
#include <math.h>
double gp(double r, int n) {
    double sum = 0;
    for(int i = 0; i <= n; i++)
        sum += pow(r, i);
    return sum;
}
int main() {
    double r;
    int n;
    printf("Enter r & n: ");
    scanf("%lf %d", &r, &n);
    printf("Sum of the geometric progression = %lf\n", gp(r, n));
    return 0;
}
