#include <stdio.h>
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int matrix_A[n][n];
    printf("Enter a %d * %d matrix:\n", n, n);
    for(int row = 0; row < n; row++)
        for(int column = 0; column < n; column++)
            scanf("%d", &matrix_A[row][column]);
    printf("(i) The upper left triangle of A:\n");
    for(int row = 0; row < n; row++) {
        for(int column = 0; column < n; column++)
            if(column < n - row)
                printf("%10d ", matrix_A[row][column]);
            else
                printf("%10d ", 0);
        printf("\n");
    }
    printf("(ii) The lower right triangle of A:\n");
    for(int row = 0; row < n; row++) {
        for(int column = 0; column < n; column++)
            if(column >= n - row - 1)
                printf("%10d ", matrix_A[row][column]);
            else
                printf("%10d ", 0);
        printf("\n");
    }
    printf("(iii) The upper right triangle of A:\n");
    for(int row = 0; row < n; row++) {
        for(int column = 0; column < n; column++)
            if(column >= row)
                printf("%10d ", matrix_A[row][column]);
            else
                printf("%10d ", 0);
        printf("\n");
    }
    printf("(iv) The lower left triangle of A:\n");
    for(int row = 0; row < n; row++) {
        for(int column = 0; column < n; column++)
            if(column <= row)
                printf("%10d ", matrix_A[row][column]);
            else
                printf("%10d ", 0);
        printf("\n");
    }
    printf("(v) The diagonal of A:\n");
    for(int row = 0; row < n; row++) {
        for(int column = 0; column < n; column++)
            if(row == column)
                printf("%10d ", matrix_A[row][column]);
            else
                printf("%10d ", 0);
        printf("\n");
    }
    printf("(vi) The reverse diagonal of A:\n");
    for(int row = 0; row < n; row++) {
        for(int column = 0; column < n; column++)
            if(row == n - column - 1)
                printf("%10d ", matrix_A[row][column]);
            else
                printf("%10d ", 0);
        printf("\n");
    }
    return 0;
}
