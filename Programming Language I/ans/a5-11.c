#include <stdio.h>
int T(int);
int main() {
    for(int n = 5; n <= 10; ++n)
        printf("T(%d) = %d\n", n, T(n));
    return 0;
}
int T(int n) {
    if(n == 1)
        return 3;
    else if(n == 2)
        return 5;
    else
        return T(n - 1) + 2 * T(n - 2);
}
