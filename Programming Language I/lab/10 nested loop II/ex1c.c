#include <stdio.h>
int main() {
    int rows;
    printf("Enter rows: ");
    scanf("%d", &rows);
    for(int i = 1; i <= rows; i++) {
        for(int j = rows - i; j >= 1; j--)
            printf(" ");
        for(int j = 1; j <= 2 * i - 1; j++)
            printf("%c", 'A' + j - 1);
        printf("\n");
    }
    return 0;
}
