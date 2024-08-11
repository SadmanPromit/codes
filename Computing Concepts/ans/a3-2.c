#include <stdio.h>
void listNumbersDesc(int start, int end);
int main() {
    int start, end;
    printf("Enter start & end: ");
    scanf("%d %d", &start, &end);
    listNumbersDesc(start, end);
    return 0;
}
void listNumbersDesc(int start, int end) {
    for(; end >= start; end--)    // Optimization
        printf("%d ", end);
    printf("\n");
}
