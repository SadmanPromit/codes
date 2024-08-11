#include <stdio.h>
int main() {
    int n;
    long long i = 1, j, sum;
    printf("Enter n: ");
    scanf("%d", &n);
    while(n > 0) {
        sum = 0;
        for(j = 1; j < i; j++)
            if(i % j == 0)
                sum += j;
        if(sum == i) {
            n--;
        }
        i++;
    }
    printf("The n-th perfect number: %lld\n", --i);
    return 0;
}
