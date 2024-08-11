#include <stdio.h>
int main() {
    int rows;
    printf("Enter rows: ");
    scanf("%d", &rows);
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= i - 1; j++)
            printf(" ");
        for(int j = rows + 1 - i; j >= 1; j--)
            printf("* ");
        printf("\n");
    }
    return 0;
}
