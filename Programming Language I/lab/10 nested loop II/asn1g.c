#include <stdio.h>
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int mid = n / 2 + n % 2;    // For even n take repeated mids
    for(int i = 1; i <= mid; i++) {
        for(int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
    for(int i = ++mid; i <= n; i++) {
        for(int j = n; j >= i; j--)
            printf("*");
        printf("\n");
    }
    return 0;
}
