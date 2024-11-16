#include <stdio.h>
int main() {
    int n;
    long long i = 1, j, sum;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("First %d prime numbers: ", n);
    while(n > 0) {
        sum = 0;
        for(j = 1; j < i; j++)
            if(i % j == 0)
                sum += j;
        if(sum == i) {
            printf("%lld, ", i);
            n--;
        }
        i++;
    }
    return 0;
}
