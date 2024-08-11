#include <stdio.h>
#include <math.h>

int main() {
    double n = 1;
    while(100 * pow(n, 2) > pow(2, n))
        n = n + 0.00001;
    printf("%lf", n);
}

