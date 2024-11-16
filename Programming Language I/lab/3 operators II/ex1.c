#include <stdio.h>
int main() {
    int n, output;
    printf("Enter n: ");
    scanf("%d", &n);
    output = n & 1;
    printf("n & 1 = %d", output);
}
