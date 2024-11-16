#include <stdio.h>
int main() {
    int n;
    long long i = 1, j, sum, sum_perfect = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    while(n > 0) {
        sum = 0;
        for(j = 1; j < i; j++)
            if(i % j == 0)
                sum += j;
        if(sum == i) {
            sum_perfect += i;
            n--;
        }
        i++;
    }
    printf("The sum of first n perfect numbers: %lld\n", sum_perfect);
    return 0;
}
