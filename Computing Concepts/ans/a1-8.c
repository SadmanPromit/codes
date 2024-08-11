#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c, discriminant, root1, root2;
    printf("Enter a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);
    discriminant  = pow(b, 2) - 4 * a * c;
    if(discriminant  == 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        printf("Real root: %f\n", root1);
    }
    else if(discriminant > 0) {
        root1 = (-b - sqrt(discriminant)) / (2 * a);
        root2 = (-b + sqrt(discriminant)) / (2 * a);
        printf("Real roots: %f, %f\n", root1, root2);
    }
    else
        printf("No real root exist.\n");
    return 0;
}

