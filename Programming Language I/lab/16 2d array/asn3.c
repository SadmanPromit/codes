#include <stdio.h>
int main() {
    int n = 3, matrix_A[n][n], cofactor1, cofactor2, cofactor3;
    printf("Enter %d * %d matrix A elements:\n", n, n);
    for(int row = 0; row < n; row++)
        for(int column = 0; column < n; column++)
            scanf("%d", &matrix_A[row][column]);
    cofactor1 = matrix_A[0][0] * (matrix_A[1][1] * matrix_A[2][2] - matrix_A[1][2] * matrix_A[2][1]);   // Cofactor for matrix_A[0][0]
    cofactor2 = matrix_A[0][1] * (matrix_A[1][0] * matrix_A[2][2] - matrix_A[1][2] * matrix_A[2][0]);   // Cofactor for matrix_A[0][1]
    cofactor3 = matrix_A[0][2] * (matrix_A[1][0] * matrix_A[2][1] - matrix_A[1][1] * matrix_A[2][0]);   // Cofactor for matrix_A[0][2]
    printf("Determinant of A = %d\n", cofactor1 - cofactor2 + cofactor3);
    return 0;
}
