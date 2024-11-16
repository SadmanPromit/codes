#include <stdio.h>
void main() {
    int i, j, N;
    printf("Enter rows: ");
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        // Print leading spaces
        for(j = 1; j <= N - i; j++)
            printf(" ");
        // Print stars after spaces
        for(j = 1; j <= N; j++) {
            if(i == 1 || i == N || j == 1 || j == N)
            printf("*");
        else
            printf(" ");
        }
        printf("\n");
    }
}
