#include <stdio.h>
#include <math.h>
int main() {
    int n;
    float sum = 1;  // Initialize for n = 1
    printf("Enter N: ");
    scanf("%d", &n);
    for(int i = 2, difference = 2; i <= n; i++) // Loop up to 2 to n
        sum += (float) (pow(pow(i, 3), 2) + i) / pow(pow(i, 2), difference++);  // ((i ^ 3) ^ 2 + i) / (i ^ 2) ^ (2 + difference)
    printf("Sum = %f\n", sum);
    return 0;
}
