#include <stdio.h>
#include <math.h>
int main() {
    int n, i = 2, output = 0;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    while(i <= n) {
        output += pow(i, 3);
        i += 3;
    }
    printf("Output: %d\n", output);
    return 0;
}
