#include <stdio.h>
int main() {
    int r, c, sum = 0;
    printf("Enter r & c: ");
    scanf("%d %d", &r, &c);
    int matrix_A[r][c];
    printf("Enter a %d * %d matrix A:\n", r, c);
    for(int row = 0; row < r; row++)
        for(int column = 0; column < c; column++) {
            scanf("%d", &matrix_A[row][column]);
            if(!(matrix_A[row][column] % 2))    // Optimal
                sum += matrix_A[row][column];
        }
    printf("The sum of even numbers in A = %d\n", sum);
    return 0;
}
