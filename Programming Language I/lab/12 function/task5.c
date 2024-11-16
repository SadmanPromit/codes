#include <stdio.h>
int round1(float n) {
    int i = n;  //integer part of n
    if(n - i >= 0.5) return i + 1;
    else return i;
}
int main() {
    float n;
    printf("Enter a number: ");
    scanf("%f", &n);
    int s = round1(n);
    printf("%d\n", s);
    return 0;
}
