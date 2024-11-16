#include <stdio.h>
void main() {
    int integer;
    printf("Enter integer: ");
    scanf("%d", &integer);
    if(integer % 2 == 0 ^ integer % 5 == 0)
        printf("Multiple of either 2 or 5 but not a multiple of both.");
    else
        printf("Not multiple of either 2 or 5 but not a multiple of both.");
}
