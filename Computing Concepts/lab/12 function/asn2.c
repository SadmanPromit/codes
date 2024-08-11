#include <stdio.h>
int power(int a, int b) {
    int result = 1;
    for(int i = 1; i <= b; i++)
        result *= a;
    return result;
}
int main() {
    int a, b;
    printf("Enter a & b: ");
    scanf("%d %d", &a, &b);
    printf("%d ^ %d = %d\n", a, b, power(a, b));
    return 0;
}
