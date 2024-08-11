#include <stdio.h>
void main() {
    int i, j, N;
    printf("No. of rows: ");
    scanf("%d", &N);
    // In each of N rows/lines
    for(i = 1; i <= N; i++) {
    // Print N stars
        for(j = 1; j <= N; j++)
            printf("*"); // j
        //Go to next line
        printf("\n");
    } // i
}
