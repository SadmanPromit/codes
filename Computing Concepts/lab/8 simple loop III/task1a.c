#include <stdio.h>
void main() {
    int n, r, m = 1, d = 1, i;
    printf("Enter n and r: ");
    scanf("%d %d", &n, &r);
    // Compute n!
    for(i = 1; i <= n; i++)
        m *= i;
    // Compute (n - r)!
    for(i = 1; i <= n - r; i++)
        d *= i;
    printf("nPr = %d\n", m / d);
}
