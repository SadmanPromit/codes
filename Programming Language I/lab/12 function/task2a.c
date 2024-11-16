#include <stdio.h>
void positiveNegativeZero(int x) {
    if(x == 0)
        printf("Zero\n");
    else if(x > 0)
        printf("Positive\n");
    else
        printf("Negative\n");
}
int main() {
    int m;
    printf("Enter an integer: ");
    scanf("%d", &m);
    positiveNegativeZero(m);
    return 0;
}
