#include <time.h>
#include <stdio.h>
int main() {
    for(int size = 16; size <= 256; size *= 2) {
        clock_t begin = clock();
        int A[size][size], B[size][size], C[size][size];
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++) {
                A[i][j] = 1;//matrix A data
                B[i][j] = 1;//matrix B data
                C[i][j] = 0;
            }
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                for(int k = 0; k < size; k++)
                    C[i][j] += (A[i][k] * B[k][j]);//matrix C multiplication calculation
            }
        }
        clock_t end = clock();
        printf("T(%d): %lfs\n", size, (double)(end - begin) / CLOCKS_PER_SEC);
    }
}
