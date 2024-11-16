#include <stdio.h>
void numberPyramid(int n);
int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    numberPyramid(n);
    return 0;
}
void numberPyramid(int n) {
    for(int i = 1, counter = 0; i <= n; i++) {
        for(int j = 1; j <= n - i; j++)
            printf(" ");
        for(int j = 1; j <= i; j++)
            printf("%d", counter++ % 10);
        printf("\n");
    }
}
