#include <stdio.h>
#define SIZE 3  // Given
int maxNum(int, int);   // Custom
int main() {
    int array2d[SIZE][SIZE], sum_diag = 0, sum_border = 0, row_sums[SIZE] = {0}, column_sums[SIZE] = {0},
        max_sum_row, max_sum_column;
    printf("Enter elements for the 2D array:\n");
    for(int row = 0; row < SIZE; ++row)
        for(int column = 0; column < SIZE; ++column) {
            scanf("%d", &array2d[row][column]);
            if(row == column)   // Diagonal Sum
                sum_diag += array2d[row][column];
            if(row == 0 || row == SIZE - 1 || column == 0 || column == SIZE - 1)    // Border Sum
                sum_border += array2d[row][column];
            row_sums[row] += array2d[row][column];  // Row Sums
            column_sums[column] += array2d[row][column];    // Column Sums
        }
    max_sum_row = row_sums[0];   // Initialize max to the first element
    max_sum_column = column_sums[0];
    for(int i = 1; i < SIZE; ++i) {     // Calculate Maximum Row and Column Sums
        max_sum_row = maxNum(max_sum_row, row_sums[i]);
        max_sum_column = maxNum(max_sum_column, column_sums[i]);
    }
    printf("Sum of main diagonal element: %d\nSum of border element: %d\n", sum_diag, sum_border);
    for(int i = 0; i < SIZE; ++i)
        printf("Row%d sum: %d\n", i, row_sums[i]);
    printf("Maximum row sum: %d\n", max_sum_row);
    for(int i = 0; i < SIZE; ++i)
        printf("Column%d sum: %d\n", i, column_sums[i]);
    printf("Maximum column sum: %d\n", max_sum_column);
    return 0;
}
int maxNum(int number1, int number2) {
    return (number1 >= number2) ? number1 : number2;
}
