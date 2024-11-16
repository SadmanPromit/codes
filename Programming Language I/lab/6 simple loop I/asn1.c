#include <stdio.h>
#include <math.h>
int main() {
    int n, i = 5, j = 2, output = 0;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    while(i <= n) {
        output += pow(i, 2);
        i += 2 * j++;
    }
    printf("Output: %d\n", output);
    return 0;
}
