#include <stdio.h>
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            // True condition when both even or odd
            if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                printf("%d ", j);
        printf("\n");
    }
    return 0;
}
