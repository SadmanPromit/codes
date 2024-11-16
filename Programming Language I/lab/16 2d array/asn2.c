#include <stdio.h>
int main() {
    int r, c;
    printf("Enter r & c: ");
    scanf("%d %d", &r, &c);
    int matrix_A[r][c], matrix_B[r][c]; // Runtime declaration
    printf("Enter %d * %d matrix A elements:\n", r, c);
    for(int row = 0; row < r; row++)
        for(int column = 0; column < c; column++)
            scanf("%d", &matrix_A[row][column]);
    printf("Enter %d * %d matrix B elements:\n", r, c);
    for(int row = 0; row < r; row++)
        for(int column = 0; column < c; column++)
            scanf("%d", &matrix_B[row][column]);
    for(int row = 0; row < r; row++) {
        for(int column = 0; column < c; column++)
            printf("%10d ", 5 * matrix_A[row][column] + 7 * matrix_B[row][column] + 9); // Optimal
        printf("\n");
    }
    return 0;
}
