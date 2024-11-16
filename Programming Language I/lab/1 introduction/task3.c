#include<stdio.h>
int main() {
    float c, f;
    printf("Insert value of C: ");
    scanf("%f", &c);
    f = c * (9 / 5) + 32;
    printf("\nF: %.2f", f);
}
