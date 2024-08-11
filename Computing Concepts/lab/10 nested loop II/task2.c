#include <stdio.h>
void main() {
    int i, j, rows;
    printf("Enter no. of rows: ");
    scanf("%d", &rows);
    int space = rows - 1;
    for(i = 1; i <= rows; ++i) {
        for(j = 1; j <= space; j++)
            printf(" ");
        for(j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
        space--;
    }
}
