#include <stdio.h>
int sumSeries(int n);
int main() {
    printf("1+ 6 + 11 + ..... + 101 = %d\n", sumSeries(101));
    return 0;
}
int sumSeries(int n) {
    if(n < 1)
        return 0;
    else
        return n + sumSeries(n - 5);
}
