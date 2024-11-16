#include <stdio.h>
int isPerfect(int x) {
    int i, sum = 0;
    for(i = 1; i <= x / 2; i++)
        if(x % i == 0)
            sum += i;
    if(sum == x)
        return 1;
    return 0;
}
int main() {
    int m;
    printf("Enter an integer: ");
    scanf("%d", &m);
    int n = isPerfect(m);
    if(!n)
       printf("Not perfect\n");
    else
       printf("Perfect\n");
}
