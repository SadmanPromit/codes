#include <stdio.h>
int main() {
    float number;
    printf("Enter a number: ");
    scanf("%f", &number);
    if((int)number != number)
        printf("Not an integer");
    else
        printf("Integer");
    return 0;
}
