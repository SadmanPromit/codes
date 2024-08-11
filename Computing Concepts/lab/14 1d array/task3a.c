#include <stdio.h>
void main() {
    int i, n;
    printf("No. of elements: ");
    scanf("%d", &n);
    int a[n], b[n], c[n];
    printf("Enter 1st array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter 2nd array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);
    // Compute sum of two arrays
    for(i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
        printf("%d * %d = %d\n", a[i], b[i], c[i]);
    }
}
