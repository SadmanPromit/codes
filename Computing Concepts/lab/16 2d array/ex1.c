#include <stdio.h>
int main() {
    int row_size = 3, column_size = 5, matrix_A[row_size][column_size];
    float n;
    printf("Enter a 3 * 5 matrix:\n");
    for(int row = 0; row < row_size; row++)
        for(int column = 0; column < column_size; column++)
            scanf("%d", &matrix_A[row][column]);
    printf("Enter n: ");
    scanf("%f", &n);
    for(int row = 0; row < row_size; row++) {
        for(int column = 0; column < column_size; column++)
            printf("%f ", matrix_A[row][column] * n);
        printf("\n");
    }
    return 0;
}
