#include<stdio.h>
void main() {
    int n, i, fact = 1;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        fact *= i;
    printf("n!: %d", fact);
}
