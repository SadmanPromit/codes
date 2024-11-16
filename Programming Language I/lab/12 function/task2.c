#include <stdio.h>
void oddEven(int x) {
    if(x % 2 == 0)
        printf("Even\n");
    else
        printf("Odd\n");
}
void main() {
    int m;
    printf("Enter an integer: ");
    scanf("%d", &m);
    oddEven(m); //function call
}
