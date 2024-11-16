#include <stdio.h>
int main() {
    int n, count = 1;
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = n - i; j >= 1; j--)
            printf(" ");
        for(int j = 1; j <= 2 * i - 1; j++)
            printf("%d", count++ % 10);
        printf("\n");
    }
    return 0;
}
