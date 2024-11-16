#include <stdio.h>
void main() {
    int n, r, p = 1, i;
    printf("Enter n and r: ");
    scanf("%d %d", &n, &r);
    // Compute nPr = (n - r + 1)(n - r + 2)…(n - 1)n
    for(i = n - r + 1; i <= n; i++)
        p *= i;
    printf("nPr: %d\n", p);
}
