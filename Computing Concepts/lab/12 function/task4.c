#include <stdio.h>
int sum(int m, int n) {
    int i, sum=0;
    for(i = m; i <= n; i++)
        sum += i;
    return sum;
}
int main() {
    int m, n;
    printf("Enter 2 integers: ");
    scanf("%d%d", &m, &n);
    int s = sum(m, n);
    printf("Sum = %d\n", s);
    return 0;
}
