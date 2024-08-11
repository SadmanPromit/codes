#include <stdio.h>
int main() {
    int side_a, side_b, side_c;
    printf("Enter triangle sides a, b, c: ");
    scanf("%d%d%d", &side_a, &side_b, &side_c);
    if(side_a + side_b > side_c && side_b + side_c > side_a && side_c + side_a > side_b)
        printf("Valid triangle.");
    else
        printf("Invalid triangle.");
    return 0;
}
