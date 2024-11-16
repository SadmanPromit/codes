#include <stdio.h>
void main() {
    int i, j, N;
    printf("No. of rows: ");
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= N; j++) {
        //Print stars in first and last row as well as in first and last column
        if(i == 1 || i == N || j == 1 || j == N)
            printf("*");
        else
            printf(" ");
        } // j
        printf("\n");
    } // i
}
