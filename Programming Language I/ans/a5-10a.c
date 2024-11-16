#include <stdio.h>
int sumSeries(int n);
int main() {
    printf("1+ 6 + 11 + ..... + 101 = %d\n", sumSeries(101));
    return 0;
}
int sumSeries(int n) {
    int sum = 0;
    for(int term = 1; term <= n; term += 5)
        sum += term;
    return sum;
}
