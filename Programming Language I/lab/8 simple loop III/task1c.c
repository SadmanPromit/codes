#include <stdio.h>
int main() {
    int n, r, c = 1, i;
    printf("Enter n and r: ");
    scanf("%d %d", &n, &r);
    // Avoid Redundant Computations
    if(r > n / 2)
        r = n - r;
    // Direct Multiplication and Division
    for(i = 0; i < r; i++) {
        c *= n - i;
        c /= i + 1;
    }
    printf("nCr: %d\n", c);
    return 0;
}
