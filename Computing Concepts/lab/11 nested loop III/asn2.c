#include <stdio.h>
int main() {
    int m, n;
    long long sum = 0;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    for(int i = m; i <= n; i++) {
        // Temporary variables only needed for each iteration
        int number = i, reverse_number = 0;
        while(number != 0) {
            reverse_number = reverse_number * 10 + number % 10;
            number /= 10;
        }
        if(i == reverse_number)
            sum += i;
    }
    printf("The sum of palindrome numbers between %d and %d = %lld\n", m, n, sum);
    return 0;
}
