#include <stdio.h>
#include <math.h>
void main() {
    int a, b, c, discriminant, root1, root2;
    printf("Enter a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);
    discriminant  = pow(b, 2) - 4 * a * c;
    if(discriminant  == 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        printf("Real root: %d", root1);
    }
    else if(discriminant > 0) {
        root2 = (-b - sqrt(discriminant)) / (2 * a);;
        printf("Real roots: %d, %d", root1, root2);
    }
    else
        printf("No real root exist.");
}
