#include <stdio.h>
int main() {
    int r, c, sum = 0;
    printf("Enter array row & column sizes: ");
    scanf("%d %d", &r, &c);
    int matrix_A[r][c]; // VLA
    printf("Enter %d * %d matrix elements:\n", r, c);
    for(int row = 0; row < r; row++)
        for(int column = 0; column < c; column++) {
            scanf("%d", &matrix_A[row][column]);
            if(row == 0 || row == r - 1 || column == 0 || column == c - 1)  // Optimal
                sum += matrix_A[row][column];
        }
    printf("Sum of main border elements = %d\n", sum);
    return 0;
}
