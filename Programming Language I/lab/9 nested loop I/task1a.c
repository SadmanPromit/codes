#include <stdio.h>
void main() {
    int i, j, m, n;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++)
            printf("*");
        printf("\n");
    }
}
