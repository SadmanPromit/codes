#include <stdio.h>
int main() {
    int n;
    printf("Enter number of row: ");
    scanf("%d", &n);
    for(int i = 1, count = 0; i <= n; i++) {
        for(int j = 1; j <= n - i; j++)
            printf("  ");
        for(int j = 1; j <= 2 * i - 1; j++)
            printf("%d ", count++ % 10);
        printf("\n");
    }
    return 0;
}
