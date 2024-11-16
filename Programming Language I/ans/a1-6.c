#include <stdio.h>
int main() {
    int integer;
    printf("Enter integer: ");
    scanf("%d", &integer);
    if(integer % 2 == 0 ^ integer % 5 == 0)
        printf("Valid number.\n");
    else
        printf("Invalid number.\n");
    return 0;
}

