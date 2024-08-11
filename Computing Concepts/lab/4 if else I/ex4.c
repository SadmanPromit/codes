#include <stdio.h>
void main() {
    int n;
    // Read integer from user
    printf("Enter n: ");
    scanf("%d", &n);
    if(n % 5 == 0 && n % 11 == 0)
        printf("Divisible by both 5 and 11.");
    else if(n % 5 == 0)
        printf("Divisible by 5");
    else if(n % 11 == 0)
        printf("Divisible by 11.");
    else
        printf("Divisible by neither 5 nor 11.");
}
