#include <stdio.h>
int main() {
    int n;
    printf("Enter number of row: ");
    scanf("%d", &n);
    int mid = n / 2 + n % 2;    // For even n take repeated mids
    for(int i = 1; i <= mid; i++) {
        for(int j = mid - i; j >= 1; j--)
            printf(" ");
        for(int j = 1; j <= 2 * i - 1; j++)
            if(j == 1 || j == 2 * i - 1)
                printf("%c", 'A' + j - 1);
            else
                printf(" ");
        printf("\n");
    }
    for(int i = ++mid; i <= n; i++) {
        for(int j = mid - n % 2 + 1; j <= i; j++)   // Adjust space for even n
            printf(" ");
        for(int j = 2 * n - 1; j >= 2 * i - 1; j--)
            if(j == 2 * n - 1 || j == 2 * i - 1)
                printf("%c", 'A' + 2 * n - 1 - j);
            else
                printf(" ");
        printf("\n");
    }
    return 0;
}
