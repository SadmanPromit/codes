#include <stdio.h>
void main() {
    int i, j, n;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
        if(i == n - j + 1 || i == n || j == n)
            printf("*");
        else
            printf(" ");
        }
        printf("\n");
    }
}
