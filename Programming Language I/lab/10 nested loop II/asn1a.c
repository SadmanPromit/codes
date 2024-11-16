#include <stdio.h>
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i - 1; j++)
            printf(" ");
        for(int j = n - i + 1; j >= 1; j--)
            if(i == 1 || i == n || j == n - i + 1 || j == 1)
                printf("*");
            else
                printf(" ");
        printf("\n");
    }
    return 0;
}
