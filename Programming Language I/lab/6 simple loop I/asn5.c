#include <stdio.h>
int main() {
    int number;
    printf("Enter number to print the multiplication table of: ");
    scanf("%d", &number);
    for(int i = 1; i <= 10; i++)
        printf("%d * %d = %d\n", number, i, number * i);
    return 0;
}
