#include <stdio.h>
void main() {
    int i, j, m, n;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        // Print leading spaces
        for(j = 1; j <= n - i; j++)
            printf(" ");
        // Print stars after spaces
        for(j = 1; j <= m; j++) {
            if(i == 1 || i == n || j == 1 || j == m)
            printf("*");
        else
            printf(" ");
        }
        printf("\n");
    }
}
