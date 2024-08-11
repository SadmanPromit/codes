#include <stdio.h>
#include <math.h>

int main() {
    double n = 2;
    while(n > pow(2, n / 8))
        n = n + 0.00001;
    printf("%lf", n);
}
