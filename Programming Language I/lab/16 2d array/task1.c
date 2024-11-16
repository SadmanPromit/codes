#include <stdio.h>
void main() {
    int A[3][3], B[3][3], row, col;
    printf("Enter elements in matrix of size 3x3: \n");
    for(row = 0; row < 3; row++)
        for(col = 0; col < 3; col++)
            scanf("%d", &A[row][col]);
    for(row = 0; row < 3; row++)    // Compute matrix B: the transpose of matrix A
        for(col = 0; col < 3; col++)
            B[row][col] = A[col][row];  // Store each row of A to each column of matrix B
    printf("\nOriginal matrix: \n");    // Prints the original matrix A
    for(row = 0; row < 3; row++) {
        for(col = 0; col < 3; col++)
            printf("%d ", A[row][col]);
        printf("\n");
    }
    printf("Transpose of matrix A: \n");    // Prints the transpose of matrix A
    for(row = 0; row < 3; row++) {
        for(col = 0; col < 3; col++)
            printf("%d ", B[row][col]);
        printf("\n");
    }
}
