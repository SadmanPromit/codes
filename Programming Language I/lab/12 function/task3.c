#include <stdio.h>
int isPrime(int x) {
    int i;
    for(i = 2; i <= x / 2; i++)
        if(x % i == 0)
            return 0;
    return 1;
}
int main() {
    int m;
    printf("Enter an integer: ");
    scanf("%d", &m);
    int n = isPrime(m);
    if(n == 0)
       printf("Not prime\n");
    else
       printf("Prime\n");
}
