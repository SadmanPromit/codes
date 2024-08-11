#include <stdio.h>
void main() {
    int i, n;
    printf("Print odd numbers till: ");
    scanf("%d", &n); // Read the upper limit
    printf("All odd numbers from 1 to %d are: \n", n);
    for(i = 1; i <= n; i++)
        if(i % 2 != 0) // Check if the number is odd
            printf("%d\n", i);
}
