#include <stdio.h>
int main() {
    int n, r, npr = 1;
    printf("Enter n, r: ");
    scanf("%d%d", &n, &r);
    for(int i = n; i >= n - r + 1; i--)
        npr *= i;
    printf("nPr: %d", npr);
    return 0;
}
